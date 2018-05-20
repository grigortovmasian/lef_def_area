#include "CRectangle.h"


CRectangle::CRectangle() {}

CRectangle::~CRectangle() {}

void CRectangle::setName(std::string & name) {
	m_layer_name = name;
}

void CRectangle::setDL(CCoordinate & dl) {
	m_dl = dl;
}

void CRectangle::setUR(CCoordinate & ur) {
	m_ur = ur;
}

double CRectangle::area() const{
	return std::abs(m_ur.getY() - m_dl.getY())*std::abs(m_ur.getX() - m_dl.getX());
}

void CRectangle::printNames(){
	std::cout << "          Rect   " << m_dl.getX() << " " << m_dl.getY() << " " << m_ur.getX() << " " << m_ur.getY() << "     " << area() << std::endl;
}

void CRectangle::createPolygon()
{
	m_poly = polygon();
	bg::append(m_poly.outer(), boost_point(m_dl.getX(), m_dl.getY()));
	bg::append(m_poly.outer(), boost_point(m_dl.getX(), m_ur.getY()));
	bg::append(m_poly.outer(), boost_point(m_ur.getX(), m_ur.getY()));
	bg::append(m_poly.outer(), boost_point(m_ur.getX(), m_dl.getY()));
	bg::append(m_poly.outer(), boost_point(m_dl.getX(), m_dl.getY()));

}

polygon CRectangle::getPolygon()
{
	createPolygon();
	return m_poly;
}