#ifndef CLAYER_H
#define CLAYER_H

#include <iostream>
#include <string>
#include "CPin.h"


class CLayer{
public:
	CLayer();
	~CLayer();
	void setName(const std::string &);
	void addPolygons(const CPin &);
	const std::string& getName() const;
	double area() const;
	double overlapArea();
	polygon getPolygon();
private:
	std::string m_layer_name;
	std::vector<CPin> m_polygons;
	polygon m_overlap_polygon;
};

#endif