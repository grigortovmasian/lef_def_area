#ifndef CDEF_FILE_H
#define CDEF_FILE_H

#include <string>
#include <iostream>
#include <fstream>


class CDEF_File {

public:
	CDEF_File();
	CDEF_File(const std::string&);
	~CDEF_File();
	void setFilePath(const std::string &);
	const std::string& getFilePath() const;
	void setTopCellName(const std::string &);
	const std::string& getTopCellName() const;
	void parse();
private:
	std::string m_topCellName;
	std::string m_file_path;
};

#endif