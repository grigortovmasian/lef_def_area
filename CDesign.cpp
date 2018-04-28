#include "CDesign.h"
#include <iostream>

CDesign::CDesign() { };

CDesign::CDesign(const CDesign& design):m_design(design.m_design) {};

CDesign::~CDesign() {};


void CDesign::addCell(CCell & newCell) {
	m_design.push_back(newCell);
}

void CDesign::showDesign() const {
	for (CCell cell:m_design) {
		cell.showCell();
	}
}

int CDesign::findCell(const std::string &cellName) const {
	for (int i=0;i<m_design.size();++i) {
		if (m_design[i].getName()==cellName) {
			return i;
		}
	}
	return -1;
}


double CDesign::getAreaByCellName(const std::string &cellName) const {
    int cellIndex=findCell(cellName);
	double area=0;
	if (cellIndex==-1) {
        std::cout<<cellName<<" CELL HASN'T FOUND"<<std::endl;
		return 0;
	}

	return m_design[cellIndex].getCellArea();	
	
}

