#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>

#define CSV_ERROR_FILE_OPEN
class Csv {
public:
	void Log(std::string value);

	std::vector< std::vector<std::string> > ReadCSV(std::string* filepath);
	void WriteCSV(std::vector< std::vector<std::string> >* data, std::string* filepath);
	std::vector<std::string> GetHeaders(std::vector<std::vector<std::string>>* data);
	std::vector<std::string> GetColumn(std::vector<std::vector<std::string>>* data, std::string* headerName);
	void AddRow(std::vector<std::string>* rowData, std::string* filepath);
	void RemoveRow(int rowIndex, std::string* filepath);

};

#endif // !CSV_H
