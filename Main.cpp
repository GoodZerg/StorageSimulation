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

	return 0;
}