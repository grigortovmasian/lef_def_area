#ifndef CCELL__H
#define CCELL__H

#include "CPin.h"
#include <string>



class CCell {
public:
	CCell();
	~CCell();

	void setName(std::string &);

	void addPin(CPin &);

private:
	std::string m_cell_name;
	std::vector<CPin> m_pins;
};


#endif