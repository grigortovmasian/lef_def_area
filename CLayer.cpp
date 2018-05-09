#include "CLayer.h"

CLayer::CLayer() :m_layer_name(""){ }
	
void CLayer::setName(const std::string& name){
		m_layer_name = name;
}

void CLayer::addPolygons(const CRectangle& rec){
		m_polygons.push_back(rec);
}

const std::string& CLayer::getName()const{
    return m_layer_name;
}

double CLayer::getLayerArea(){
    double a = 0;
    for (int i = 0; i < m_polygons.size(); i++)
    {
       // a += m_polygons[i].area();
    }
    return a;
}