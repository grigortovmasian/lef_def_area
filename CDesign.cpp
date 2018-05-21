#include "CDesign.h"


CDesign::CDesign() {};

CDesign::~CDesign() {};

void CDesign::addCell(CCell & newCell) {
	m_design.push_back(newCell);
}

int CDesign::findCell(const std::string &cellName) const {
	for (int i = 0; i<m_design.size(); ++i) {
		if (m_design[i].getName() == cellName) {
			return i;
		}
	}
	return -1;
}

double CDesign::getAreaByCellName(const std::string &cellName) {
	int cellIndex = findCell(cellName);
	double area = 0;
	if (cellIndex == -1) {
		std::cout << cellName << " CELL HASN'T FOUND" << std::endl;
		return 0;
	}

	std::cout<<"Top cell area [ without overlap calculation ] = "<<m_design[cellIndex].getCellArea()<<std::endl;
	return 	m_design[cellIndex].getCellOverlapArea();
}

