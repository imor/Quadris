#ifndef __POINT_H__
#define __POINT_H__

// this class represents a point on a grid where unit distance is 1 and only integral 
// increments are allowed
class Point
{
public:
	Point() : x(0), y(0)
	{

	}

	Point(int otherX, int otherY) : x(otherX), y(otherY)
	{

	}

	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
private:
	int x;
	int y;
};


inline int Point::getX() const
{
	return x;
}

inline int Point::getY() const
{
	return y;
}

inline void Point::setX(int otherX)
{
	x = otherX;
}

inline void Point::setY(int otherY)
{
	y = otherY;
}

#endif //__POINT_H__