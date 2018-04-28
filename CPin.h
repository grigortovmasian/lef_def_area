#ifndef CPIN__H
#define CPIN__H

#include "CRectangle.h"
#include <string>
#include <vector>



class CPin {
public:
	CPin();
	CPin(const CPin&);
	~CPin();

    void showPin() const;
	void setName(std::string &);
	void addPolygon(CRectangle &);
	double getPinArea() const;

private:
	std::string m_pin_name;
	std::vector<CRectangle> m_polygons;
};

#endif
