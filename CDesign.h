#ifndef CDESIGN_H
#define CDESIGN_H

#include <iostream>
#include <string>
#include <vector>
#include "CCell.h"

class CDesign {

public:
	CDesign();
	~CDesign();
	void addCell(CCell &);
	void printNames();
	int findCell(const std::string&) const;
	double getAreaByCellName(const std::string &);
protected:
	std::vector <CCell> m_design;
};

#endif
