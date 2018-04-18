#include "CCell.h"

CCell::CCell() {}
CCell::~CCell() {}

void CCell::setName(std::string & name) {
	m_cell_name = name;
}

void CCell::addPin(CPin & newPin) {
	m_pins.push_back(newPin);
}