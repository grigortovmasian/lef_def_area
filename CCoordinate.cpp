#include "CCoordinate.h"

CCoordinate::CCoordinate() {}

CCoordinate::CCoordinate(const CCoordinate& coordinate):m_x(coordinate.m_x),m_y(coordinate.m_y){
	
}

CCoordinate::~CCoordinate() {}

void CCoordinate::showCoordinate() const{
	std::cout<<m_x<<" "<<m_y<<" ";
}

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
