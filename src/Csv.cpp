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