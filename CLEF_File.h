#ifndef CLEF_FILE_H
#define CLEF_FILE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CDesign.h"

class CLEF_File {

public:
	CLEF_File();
	CLEF_File(const std::string &);
	~CLEF_File();
	void setFilePath(const std::string &);
	const std::string& getFilePath() const;
	void parse(CDesign *)const;
	void detectCell(std::ifstream &, CCell &)const;
	void detectLayer(std::ifstream &, CCell&)const;
	void detectPin(std::ifstream &, CPin &, std::string&)const;
private:
	std::string m_file_path;
};

#endif