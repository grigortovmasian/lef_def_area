#ifndef CDESIGN__H
#define CDESIGN__H

#include "CCell.h"

class CDesing {
public:
	CDesing();
	~CDesing();

	void addCell(CCell & newCell);

protected:
	std::vector <CCell> m_design;
};

#endif