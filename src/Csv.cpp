#include "Csv.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
#define CSV_ERROR_FILE_OPEN "The file doesn't exist"


void Csv::Log(string value) {
	cout << value << endl;
}

vector< vector<string> > Csv::ReadCSV(string* filepath) {
	vector<vector<string>> data;
	ifstream file;
	file.open(*filepath);

	if (file.good()) {
		string line;
		string cell;

		while (getline(file, line)) {
			data.push_back(vector<string>());

			stringstream lineStream(line);

			while (getline(lineStream, cell, ',')) {
				data.back().push_back(cell);
			}
		}
	}
	else {
		Csv::Log(CSV_ERROR_FILE_OPEN);
	}
	file.close();


	return data;
}

void Csv::WriteCSV(vector<vector<string>>* data, string* filepath) {
	ofstream file;
	file.open(*filepath);

	if (file.good()) {
		for (vector<string> row : *data) {
			for (string cell : row) {
				file << cell << ",";
			}
			file << endl;
		}
	}
	else {
		Csv::Log(CSV_ERROR_FILE_OPEN);
	}
	file.close();
}

vector<string> Csv::GetHeaders(vector<vector<string>>* data) {
    return (*data)[0];
}

vector<string> Csv::GetColumn(vector<vector<string>>* data, string* headerName) {
	vector<string> column;

	int headerIndex = -1;

	for (int i = 0; i < (*data)[0].size(); i++) {
		if ((*data)[0][i] == *headerName) {
			headerIndex = i;
			break;
		}
	}

	for (int i = 0; i < (*data).size(); i++) {
		if (headerIndex >= 0) {
			column.push_back((*data)[i][headerIndex]);
		}
	}
	return column;
}

void Csv::AddRow(vector<string>* rowData, string* filepath) {
	ofstream file;
	file.open(*filepath, ios::app);
	
	if (file.is_open()) {
		for (const string cell : *(rowData)) {
			file << cell << ",";
		}
		file << endl;

		file.close();
	}
	else {
		Csv::Log(CSV_ERROR_FILE_OPEN);
	}
}

void Csv::RemoveRow(int rowIndex, string* filepath) {
	vector<vector<string>> data = Csv::ReadCSV(filepath);

	if (rowIndex >= 0 && rowIndex < data.size()) {
		data.erase(data.begin() + rowIndex);
	}

	ofstream file;
	file.open(*filepath, ios::trunc);

	for (vector<string> row : data) {
		for (int i = 0; i < row.size(); i++) {
			file << row[i];
			if (i < row.size() - 1) {
				file << ",";
			}
		}
		file << endl;
	}
}