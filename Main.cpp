//#include "Factory.h"
//#include "Shop.h"
#include "ExcelEditor.h"


int main() {
	ExcelEditor editor("cock.xls", 1);
	editor.NextDay();
	editor.WriteText(0, L"Я пидорас!");
	editor.EndEditing();
	return 0;
}