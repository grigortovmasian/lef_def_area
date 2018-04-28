#ifndef CLEF__H
#define CLEF__H

#include "CDesign.h"
#include <string>

class CLEF {
public:
	CLEF() {}
	CLEF(const std::string & path) :m_file_path(path) {}
	inline ~CLEF() {};

	void setName(std::string & path) {
		m_file_path = path;
	}

	void parse(CDesign *)const;
	void detectCell(std::ifstream &, CCell &)const;
	void detectPin(std::ifstream &, CPin &)const;
private:
	std::string m_file_path;
};


#endif
