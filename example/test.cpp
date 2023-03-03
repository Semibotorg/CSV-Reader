#include "../src/Csv.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // create an object of the Csv class
    Csv csv;
    string filepath = "test.csv";
    // write data to a CSV file
    vector<vector<string>> dataTest = {
        {"Name", "Age"},
        {"Mike",  "28"},
        {"Joe",   "21"},
        {"Ahmed", "19"}
    };
    csv.WriteCSV(&dataTest, &filepath);

    // read data from a CSV file
    vector<vector<string>> data = csv.ReadCSV(&filepath);

    // print the data
    cout << "--data--" << endl;
    for (vector<string> row : data) {
        for (string cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
    cout << "\n----" << endl;
    // get the headers
    vector<string> headers = csv.GetHeaders(&data);
    cout << "--headers--" << endl;
    for (string header : headers) {
        cout << header << "\t";
    }
    cout << "\n----" << endl;

    // get a specific column
    string headerName = "Age";
    vector<string> column = csv.GetColumn(&data, &headerName);
    for (string cell : column) {
        cout << cell << "\t";
    }
    cout << endl;

    // add a row to the CSV file
    vector<string> newRow = { "John Doe", "25" };
    csv.AddRow(&newRow, &filepath);

    // remove a row from the CSV file
    int rowIndex = 1;
    csv.RemoveRow(rowIndex, &filepath);

    // print the data after the row has been removed
    cout << "row - rmeoved" << endl;
    for (vector<string> row : data) {
        for (string cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }
    return 0;
}
