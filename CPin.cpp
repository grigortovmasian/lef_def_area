#include "CPin.h"

CPin::CPin() {}

CPin::~CPin() {}

void CPin::setName(std::string & name) {
	m_pin_name = name;
}

void CPin::addPolygon(CRectangle & newItem) {
	m_polygons.push_back(newItem);
}