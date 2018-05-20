#include "CLayer.h"


CLayer::CLayer() :m_layer_name("") {}

CLayer::~CLayer() {}

void CLayer::setName(const std::string& name){
	m_layer_name = name;
}

void CLayer::addPolygons(const CPin& pin){
	m_polygons.push_back(pin);
}

const std::string& CLayer::getName() const {
	return m_layer_name;
}

double CLayer::area() const {
	double layerArea = 0;
	for (int i = 0; i < m_polygons.size(); i++) {
		layerArea += m_polygons[i].area();
	}
	return layerArea;
}

double CLayer::overlapArea() {
	std::vector<polygon> p_vec;
	m_polygons[0].overlapArea();
	polygon p1 = m_polygons[0].getPolygon();
	p_vec.push_back(p1);
	for (int i = 1; i < m_polygons.size(); ++i)	{
		m_polygons[i].overlapArea();
		p_vec = std::vector<polygon>();
		polygon p2 = m_polygons[i].getPolygon();
		boost::geometry::union_(p1, p2, p_vec);

		BOOST_FOREACH(polygon const& p, p_vec){
			p1 = p;
		}
	}
	double overlap_area = 0;
	BOOST_FOREACH(polygon const& p, p_vec){
		overlap_area = boost::geometry::area(p);
		m_overlap_polygon = p;
	}
	return overlap_area;
}

polygon CLayer::getPolygon(){
	return m_overlap_polygon;
}
