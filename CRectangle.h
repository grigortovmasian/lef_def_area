#ifndef CRECTANGLE__H
#define CRECTANGLE__H

#include "CCoordinate.h"
#include <string>


class CRectangle {
public:
	CRectangle();
	~CRectangle();

	void setName(std::string &);

	void setDL(CCoordinate &);

	void setUR(CCoordinate &);

private:
	std::string m_layer_name;
	CCoordinate m_dl;
	CCoordinate m_ur;
};

#endif 