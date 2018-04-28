#include "CRectangle.h"

CRectangle::CRectangle() {}

CRectangle::~CRectangle() {}

void CRectangle::showRectangle() const{
	m_dl.showCoordinate();
	m_ur.showCoordinate();

}

void CRectangle::setName(std::string & name) {
	m_layer_name = name;
}

void CRectangle::setDL(CCoordinate & dl) {
	m_dl = dl;
}

void CRectangle::setUR(CCoordinate & ur) {
	m_ur = ur;
}

double CRectangle::getRectangleArea() const {
	double width=std::abs(m_dl.getX()-m_ur.getX());
	double height=std::abs(m_dl.getY()-m_ur.getY());

	return width*height;

}
