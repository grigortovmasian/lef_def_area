#ifndef CREACTANGLE_H
#define CRECTANGLE_H

#include <string>
#include <iostream>
#include "CCoordinate.h"
#include <cmath>


#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/io/wkt/wkt.hpp>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> boost_point;
typedef bg::model::polygon<boost_point> boost_polygon;
typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

class CRectangle {

public:
	CRectangle();
	~CRectangle();
	void setName(std::string &);
	void setDL(CCoordinate &);
	void setUR(CCoordinate &);
	double area() const;
	void createPolygon();
	polygon getPolygon();
	void printNames();
private:
	std::string m_layer_name;
	CCoordinate m_dl;
	CCoordinate m_ur;
	polygon m_poly;
};

#endif