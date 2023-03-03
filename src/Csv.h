#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>

class Csv {
public:
	void Log(std::string value);

	std::vector< std::vector<std::string> > ReadCSV(std::string* filepath);
	void WriteCSV(std::vector< std::vector<std::string> >* data, std::string* filepath);
};

#endif // !CSV_H
