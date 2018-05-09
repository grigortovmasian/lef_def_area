#ifndef CLAYER_H
#define CLAYER_H

#include "CRectangle.h"
#include <vector>

class CLayer{
public:
	CLayer();
	void setName(const std::string&);
	void addPolygons(const CRectangle&);
	const std::string& getName()const;
	double getLayerArea();

private:
	std::string m_layer_name;
	std::vector<CRectangle> m_polygons;
};

#endif