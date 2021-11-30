#include "ExcelEditor.h"

ExcelEditor::ExcelEditor(string fileName, int dayCount) : dayCounter_(0), fileName_(fileName), 
	rawCounter_(0) {
	document_ = BasicExcel(fileName_.c_str());
	document_.New(dayCount);
	for (int i = 0; i < dayCount; ++i) {
		std::wstring tmp(L"Δενό " + std::to_wstring(i + 1));
		document_.RenameWorksheet(i, tmp.c_str());
	}
}

void ExcelEditor::NextDay() {
	++dayCounter_;
	rawCounter_ = 0;
	currentDay_ = document_.GetWorksheet(dayCounter_ - 1);
}

void ExcelEditor::NextRaw() {
	++rawCounter_;
}

void ExcelEditor::WriteText(int column, wstring text) {
	BasicExcelCell* cell = currentDay_->Cell(rawCounter_, column);
	cell->SetWString(text.c_str());
}

void ExcelEditor::WriteData(int startColumn, vector<double>& data) {
	BasicExcelCell* cell;
	for (int i = startColumn; i < startColumn + data.size(); ++i) {
		cell = currentDay_->Cell(rawCounter_, i);
		cell->SetDouble(data[i - startColumn]);
	}
}

void ExcelEditor::EndEditing() {
	document_.SaveAs(fileName_.c_str());
}