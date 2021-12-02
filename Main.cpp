#include "Factory.h"
#include "Shop.h"
#include "ExcelEditor.h"
#include "Storage.h"
#include "Manager.h"
#include <ctime>

int main() {
	
	setlocale(LC_ALL, "Russian");


	int daysCount = 0, productCount = 0, shelfsSize = 0, 
		maxOrderProductCount = 0, shopsCount = 0;
	string fileName = "";

	std::cout << "Количество дней: ";
	std::cin >> daysCount;
	std::cout << "\n";
	std::cout << "Количество видов продуктов: ";
	std::cin >> productCount;
	std::cout << "\n";
	std::cout << "Размер полок: ";
	std::cin >> shelfsSize;
	std::cout << "\n";
	std::cout << "Максимальное возможный размер заказа: ";
	std::cin >> maxOrderProductCount;
	std::cout << "\n";
	std::cout << "Количество магазинов: ";
	std::cin >> shopsCount;
	std::cout << "\n";
	std::cout << "Название файла с результатом симуляции: ";
	std::cin >> fileName;
	fileName += ".xls";
	std::cout << "\n";

	Manager* manager = new Manager();
	Factory* factory = new Factory();
	Storage* storage = new Storage(productCount, shelfsSize, daysCount, fileName, factory, manager);
	manager->SetStorage(storage);

	vector<Shop*> shops = { };

	for (size_t i = 0; i < shopsCount; i++) {
		shops.push_back(new Shop(productCount, maxOrderProductCount, storage ));
	}

	for (size_t i = 0; i < daysCount; i++) {
		storage->Update();
		for (auto i : shops) {
			i->Update();
		}
		factory->Update();
		manager->PrintMoney();
	}

	delete manager;
	delete factory;
	delete storage;
	for (size_t i = 0; i < shopsCount; i++) {
		delete shops[i];
	}

	return 0;
}