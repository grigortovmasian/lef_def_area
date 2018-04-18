#ifndef CCOORDINATE__H
#define CCOORDINATE__H

class CCoordinate {
public:
	CCoordinate();
	~CCoordinate();

	void setX(double);

	void setY(double);

	double getX() const;

	double getY() const;

private:
	double m_x;
	double m_y;
};

#endif
