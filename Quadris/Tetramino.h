#ifndef __TETRAMINO_H__
#define __TETRAMINO_H__

#include "Texture.h"
#include "Point.h"
#include <deque>
#include <vector>

class Tetramino
{
public:
	Tetramino(int originX, int originY, Texture* texture);
	virtual ~Tetramino(){};
	std::deque<Point> getBlockOffsets() const;
	void setOrigin(int originX, int originY);
	const Point& getOrigin() const;
	Texture* getTexture();
	virtual void rotateCCW();
	virtual void rotateCW();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void offset(int x, int y);
	void draw(int drawBlockBelow);
	static Tetramino* getRandomTetramino(unsigned int gridOriginX, unsigned int gridOriginY);
	const std::vector<Point>* getWallKickData();
protected:
	std::deque<Point> blockOffsets;
	int rotation; // can have values of 0, 90, 180 & 270 only
	Point origin; // origin of the Tetramino
	Texture* texture;
	std::vector<std::vector<Point>> wallKickData;
};

inline void Tetramino::setOrigin(int x, int y)
{
	origin.setX(x);
	origin.setY(y);
}

inline const Point& Tetramino::getOrigin() const
{
	return origin;
}

inline Texture* Tetramino::getTexture()
{
	return texture;
}

inline const std::vector<Point>* Tetramino::getWallKickData()
{
	return &wallKickData[rotation / 90];
}

#endif //__TETRAMINO_H__