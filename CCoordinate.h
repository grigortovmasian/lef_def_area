#ifndef CCOORDINATE_H
#define CCOORDINATE_H

#include <string>
#include <iostream>

class CCoordinate {

public:
	CCoordinate();
	~CCoordinate();
	void setX(double);
	void setY(double y);
	double getX()const;
	double getY()const;

private:
	double m_x;
	double m_y;
};

#endif