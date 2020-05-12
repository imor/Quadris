#ifndef __TETRAMINO_H__
#define __TETRAMINO_H__

#include "Texture.h"
#include "Point.h"
#include <deque>
#include <vector>

class Tetramino
{
public:
	Tetramino(int originX, int originY, unsigned int pivotBlockIndex, Texture* texture);
	std::deque<Point> getBlockPositions() const;
	const unsigned int getOrigin() const;
	Texture* getTexture();
	virtual void rotateCCW();
	virtual void rotateCW();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void moveBy(int x, int y);
	void draw(int drawBlockBelow);
	static Tetramino* getRandomTetramino(unsigned int gridOriginX, unsigned int gridOriginY);
	const std::vector<Point>* getWallKickData();
protected:
	virtual void setOrigin(int originX, int originY);
	std::deque<Point> blockPositions;
	int rotation; // can have values of 0, 90, 180 & 270 only
	unsigned int pivotBlockIndex; // origin of the Tetramino
	Texture* texture;
	std::vector<std::vector<Point>> wallKickData;
};

inline const unsigned int Tetramino::getOrigin() const
{
	return pivotBlockIndex;
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