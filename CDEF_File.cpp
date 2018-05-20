#include "CDEF_File.h"

CDEF_File::CDEF_File() {}

CDEF_File::CDEF_File(const std::string& file_path) : m_file_path(file_path) {}

CDEF_File::~CDEF_File() {}

void CDEF_File::setFilePath(const std::string& file_path) {
	m_file_path = file_path;
}

const std::string& CDEF_File::getFilePath() const {
	return m_file_path;
}

void CDEF_File::setTopCellName(const std::string& topCellName) {
	m_topCellName = topCellName;
}

const std::string& CDEF_File::getTopCellName() const {
	return m_topCellName;
}

void CDEF_File::parse()  {
	std::ifstream input(m_file_path);
	std::string line;

	if (!input.is_open()) {
		std::cout << "Couldn't open file!" << m_file_path << " is the wrong path\n";
	}
	while (input >> line)
	{
		if (line == "TOP_CELL") {
			input >> m_topCellName;
			break;
		}
	}

}
