#include "Factory.h"
#include "Shop.h"
#include "ExcelEditor.h"
#include "Storage.h"
#include "Manager.h"

int main() {
//	ExcelEditor editor("cock6.xls", 3);
//	editor.NextDay();
//	editor.WriteText(0, L"Я пидорас!");
//	editor.EndEditing();

	Manager* manager = new Manager();
	Factory* factory = new Factory();
	Storage* storage = new Storage(2, 10, factory, manager);
	manager->SetStorage(storage);

	vector<Shop*> shops = {
		new Shop(5, storage),
		new Shop(5, storage),
		new Shop(5, storage),
		new Shop(5, storage)
	};

	for (size_t i = 0; i < 20; i++) {
		for (auto i : shops) {
			i->Update();
		}
		storage->Update();
		factory->Update();
	}

	return 0;
}