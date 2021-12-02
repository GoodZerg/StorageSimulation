#pragma once
#include "ExcelFormat\ExcelFormat.h"
using namespace ExcelFormat;

class ExcelEditor {
public:
	ExcelEditor(string, int);
	void NextDay();
	void NextRaw();
	void StepToRaw(int raw);
	void WriteData(int, vector<double>&);
	void WriteText(int, wstring);
	void EndEditing();
private:
	BasicExcel document_;
	string fileName_;
	BasicExcelWorksheet* currentDay_;
	int dayCounter_;
	int rawCounter_;
};