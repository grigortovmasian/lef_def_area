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