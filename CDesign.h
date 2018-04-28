#ifndef CDESIGN__H
#define CDESIGN__H

#include "CCell.h"

class CDesign {
public:
	CDesign();
	CDesign(const CDesign&);
	~CDesign();

	void addCell(CCell & newCell);
	void showDesign() const;
	int findCell(const std::string&) const;
	double getAreaByCellName(const std::string &) const;

protected:
	std::vector <CCell> m_design;
};

#endif
