#include "CCell.h"

CCell::CCell() {}
CCell::~CCell() {}

void CCell::setName(std::string & name) {
	m_cell_name = name;
}


const std::string&  CCell::getName() const{
	return m_cell_name;
}


void CCell::addPin(CPin & newPin) {
	m_pins.push_back(newPin);
}


void CCell::showCell() const {	
   for(CPin pin:m_pins){
	   pin.showPin();
   }
}


double CCell::getCellArea() const {
	double cellArea=0;
	for (int i=0;i<m_pins.size();++i) {
		cellArea+=m_pins[i].getPinArea();
	}
	return cellArea;
}


