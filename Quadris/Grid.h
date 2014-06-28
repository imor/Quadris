#ifndef __GRID_H__
#define __GRID_H__

#include "Tetramino.h"
#include "Texture.h"
#include <deque>

class Grid
{
public:
	Grid(unsigned int originX, unsigned int originY, unsigned int width, unsigned int height, Texture* gridTexture);
	void draw();
	bool canMoveLeft(Tetramino& tetramino);
	bool canMoveRight(Tetramino& tetramino);
	void addTetraminoToGrid(Tetramino& tetramino);
	std::deque<std::deque<bool> >& getBlocks();
	int removeCompletedLines();
	bool gameOver() const;
	long getScore() const;
	void setScore(long s);
	void setLinesCompleted(int l);
	int getLinesCompleted() const;
	void cleanUp();
	bool isValidPosition(Tetramino& tetramino);
	bool touchingFloorOrBlock(Tetramino& tetramino);
private:
	std::deque<std::deque<bool>> blocks;
	std::deque<std::deque<Texture*>> blockTextures; 
	int numberOfLinesCompleted;
	long score;
	Texture* gridTexture;
	unsigned int originX;
	unsigned int originY;
	unsigned int width;
	unsigned int height;
};

inline std::deque<std::deque<bool> >& Grid::getBlocks()
{
	return blocks;
}

inline long Grid::getScore() const
{
	return score;
}

inline int Grid::getLinesCompleted() const
{
	return numberOfLinesCompleted;
}

inline void Grid:: setScore(long s)
{
	score = s;
}

inline void Grid:: setLinesCompleted(int l)
{
	numberOfLinesCompleted = l;
}

#endif //__GRID_H__