#ifndef CPIN__H
#define CPIN__H

#include "CRectangle.h"
#include <string>
#include <vector>



class CPin {
public:
	CPin();
	~CPin();

	void setName(std::string &);

	void addPolygon(CRectangle &);

private:
	std::string m_pin_name;
	std::vector<CRectangle> m_polygons;
};


#endif