#ifndef CPIN_H
#define CPIN_H

#include <iostream>
#include <string>
#include <vector>
#include "CRectangle.h"

class CPin {

public:
	CPin();
	~CPin();
	void setName(std::string &);
	void setLayerName(const std::string &);
	void addPolygon(CRectangle &);
	double area() const;
	double overlapArea();
	polygon getPolygon();
	void printNames();
private:
	std::string m_layer_name;
	std::string m_pin_name;
	std::vector<CRectangle> m_polygons;
	polygon m_overlap_polygon;
};

#endif