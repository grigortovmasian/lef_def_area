#ifndef CRECTANGLE__H
#define CRECTANGLE__H

#include "CCoordinate.h"
#include <string>
#include <cmath>

class CRectangle {
public:
	CRectangle();
	~CRectangle();

    void showRectangle() const;
	void setName(std::string &);
	void setDL(CCoordinate &);
	void setUR(CCoordinate &);
    double getRectangleArea() const;


private:
	std::string m_layer_name;
	CCoordinate m_dl;
	CCoordinate m_ur;
};

#endif 
