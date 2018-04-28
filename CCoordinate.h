#ifndef CCOORDINATE__H
#define CCOORDINATE__H

#include <iostream>

class CCoordinate {
public:
	CCoordinate();
	CCoordinate(const CCoordinate&);
	~CCoordinate();

    void showCoordinate() const;
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;

private:
	double m_x;
	double m_y;
};

#endif
