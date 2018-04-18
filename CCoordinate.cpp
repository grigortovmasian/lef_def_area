#include "CCoordinate.h"

CCoordinate::CCoordinate() {}

CCoordinate::~CCoordinate() {}

void CCoordinate::setX(double x) {
	m_x = x;
}

void CCoordinate::setY(double y) {
	m_y = y;
}

double CCoordinate::getX() const {
	return m_x;
}

double CCoordinate::getY() const {
	return m_y;
}