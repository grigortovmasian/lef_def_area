#include "CPin.h"

CPin::CPin() {}

CPin::~CPin() {}

CPin::CPin(const CPin& pin):m_pin_name(pin.m_pin_name),m_polygons(pin.m_polygons) {

}

void CPin::showPin() const{
	for(CRectangle rectangle:m_polygons){
		rectangle.showRectangle();
		//std::cout<<std::endl;
	}
}

void CPin::setName(std::string & name) {
	m_pin_name = name;
}

void CPin::addPolygon(CRectangle & newItem) {
	m_polygons.push_back(newItem);
}

double CPin::getPinArea() const {
	double pinArea=0;
	for (int i=0;i<m_polygons.size();++i) {
		pinArea+=m_polygons[i].getRectangleArea();
	}
	std::cout<<"Pin name: "<<m_pin_name<<" area: "<<pinArea<<std::endl;
	std::cout<<std::endl;
	return pinArea;
}
