#include "Storage.h"

Storage::Storage(int productNum, int shelfMaxSize, int daysCount, string fileName, Factory* fa, ISimulate* manager) {
	for (auto i : ProductsClass) {
		shelfs_[i.first] = new Shelf(shelfMaxSize);
		for (; !shelfs_[i.first]->isFull();) {
			shelfs_[i.first]->PutPackage(new Package(i.second));
		}
	}

	excelEditor_ = new ExcelEditor(fileName, daysCount);
	//excelEditor_->WriteText(0, L"Я пидорас!");
	// for (auto i : shelfs_) {
	// 	std::cout << i.first << ": " << i.second->GetPackagesCount() << "\n";
	// }
	// std::cout << "\n";
	// std::cout << "\n";
	// std::cout << "\n";

	manager_ = manager;
	factory_ = fa;
}

Storage::~Storage() {

	excelEditor_->EndEditing();
	delete excelEditor_;

	shelfs_.clear();
	orders_.clear();
}

void Storage::Update() {
	excelEditor_->NextDay();
	excelEditor_->NextRaw();
	excelEditor_->WriteText(1, L"Состояние склада на начало дня");
	excelEditor_->NextRaw();
	excelEditor_->WriteText(1, L"Тип товара на полке");
	excelEditor_->WriteText(2, L"Количество");
	excelEditor_->NextRaw();

	for (auto i : shelfs_) {
		excelEditor_->WriteText(1, wstring(i.first.begin(), i.first.end()));
		//std::cout << i.first << ": " << i.second->GetPackagesCount() << "\n";
		excelEditor_->WriteText(2, std::to_wstring(i.second->GetPackagesCount()));
		excelEditor_->NextRaw();
	}

	excelEditor_->NextRaw();
	excelEditor_->NextRaw();

	excelEditor_->WriteText(1, L"Заказы на сегодня(до обработки менеджером)");
	excelEditor_->NextRaw();
	excelEditor_->WriteText(1, L"Тип товара");
	excelEditor_->WriteText(2, L"Количество");
	excelEditor_->NextRaw();

	for (auto i : orders_) {
		excelEditor_->WriteText(1, wstring(i.first.begin(), i.first.end()));
		vector<double> tmp = {};
		for (auto j : i.second) {
			tmp.push_back(static_cast<double>(j->packageCount));
		}
		excelEditor_->WriteData(2, tmp);
		excelEditor_->NextRaw();
	}

	excelEditor_->NextRaw();
	excelEditor_->NextRaw();

	for (auto i : shelfs_) {
		std::cout << i.first << ": " << i.second->GetPackagesCount() << "\n";
	}
	std::cout << "\n";

	for (auto i: shelfs_) {
		i.second->Update();
	}

	manager_->Update();

	for (auto i : sendProduct_) {
		CompleteOrder(i);
	}
	sendProduct_.clear();


	for (auto i : orders_) {
		i.second.clear();
	}
	orders_.clear();
}

void Storage::TakeOrder(Order* order) {
	orders_[order->productType].push_back(order);
}

void Storage::TakePackages(Order* order) {
	for (int i = 0; i < order->packageCount; ++i) {
		auto pack = new Package(ProductsClass[order->productType]);
		waitingFromFactory_.erase(order->productType);
		shelfs_[order->productType]->PutPackage(pack);
	}
	delete order;
}

void Storage::CreateOrder(int productType, int packageCount) {
	Order* order = new Order();
	order->customer_ = this;
	order->contractor_ = factory_;
	order->productType = currentSimulationProducts[productType];
	order->packageCount = packageCount;
	factory_->AddOrder(order);
}

void Storage::CompleteOrder(Order* order) {
	for (int i = 0; i < order->packageCount; i++) {
		dynamic_cast<IMoneyCount*>(manager_)->AddMoney(&shelfs_[order->productType]->TakePackage()->product_);
	}
	dynamic_cast<ITakePackages*>(order->customer_)->TakePackages(order);
}
