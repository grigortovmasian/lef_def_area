#include "CPin.h"

CPin::CPin() {}
CPin::~CPin() {}

void CPin::setName(std::string & name) {
	m_pin_name = name;
}

void CPin::setLayerName(const std::string& name){
	m_layer_name = name;
}

void CPin::addPolygon(CRectangle & newItem) {
	m_polygons.push_back(newItem);
}

double CPin::area() const {
	double pinArea = 0;
	for (int i = 0; i < m_polygons.size(); ++i) {
		pinArea += m_polygons[i].area();
	}
	return pinArea;
}

double CPin::overlapArea()  {
	std::vector<polygon> p_vec;
	polygon p1 = m_polygons[0].getPolygon();
	p_vec.push_back(p1);
	for (int i = 1; i < m_polygons.size(); ++i)
	{
		p_vec = std::vector<polygon>();
		polygon p2 = m_polygons[i].getPolygon();
		boost::geometry::union_(p1, p2, p_vec);

		BOOST_FOREACH(polygon const& p, p_vec){
			p1 = p;
		}
	}
	double overlap_area = 0;
	BOOST_FOREACH(polygon const& p, p_vec)
	{
		overlap_area = boost::geometry::area(p);
		m_overlap_polygon = p;
	}
	return overlap_area;
	
}

polygon CPin::getPolygon() {
	return m_overlap_polygon;
}

void CPin::printNames(){
	std::cout << "        " << m_pin_name << "  " << m_layer_name << "  " << area() << std::endl;
	for (int i = 0; i < m_polygons.size(); ++i)
		m_polygons[i].printNames();
}