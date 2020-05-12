#include "Tetramino.h"
#include "Grid.h"
#include "Crate.h"
#include "LeftL.h"
#include "LeftStep.h"
#include "RightL.h"
#include "RightStep.h"
#include "Slab.h"
#include "VictoryStand.h"
#include "Game.h"
#include <random>

using namespace std;

Tetramino::Tetramino(int originX, int originY, unsigned int pivotBlockIndex, Texture* texture) :
	rotation(0), texture(texture), pivotBlockIndex(pivotBlockIndex)
{
	for( int i = 0; i < 4; i++)
	{
		blockPositions.push_back(Point());
		wallKickData.push_back(vector<Point>());
	}

	wallKickData[0].push_back(Point(0, 0));
	wallKickData[0].push_back(Point(-1, 0));
	wallKickData[0].push_back(Point(-1, 1));
	wallKickData[0].push_back(Point(0, -2));
	wallKickData[0].push_back(Point(-1, -2));

	wallKickData[1].push_back(Point(0, 0));
	wallKickData[1].push_back(Point(-1, 0));
	wallKickData[1].push_back(Point(-1, -1));
	wallKickData[1].push_back(Point(0, 2));
	wallKickData[1].push_back(Point(-1, 2));

	wallKickData[2].push_back(Point(0, 0));
	wallKickData[2].push_back(Point(1, 0));
	wallKickData[2].push_back(Point(1, 1));
	wallKickData[2].push_back(Point(0, -2));
	wallKickData[2].push_back(Point(1, -2));

	wallKickData[3].push_back(Point(0, 0));
	wallKickData[3].push_back(Point(1, 0));
	wallKickData[3].push_back(Point(1, -1));
	wallKickData[3].push_back(Point(0, 2));
	wallKickData[3].push_back(Point(1, 2));
}

void Tetramino::setOrigin(int x, int y)
{
}

std::deque<Point> Tetramino::getBlockPositions() const
{
	return blockPositions;
}

void Tetramino::rotateCCW()
{
	rotation -= 90;
	if (rotation == -90)
	{
		rotation = 270;
	}

	int originX = blockPositions[pivotBlockIndex].getX();
	int originY = blockPositions[pivotBlockIndex].getY();
	//A point (x,y) becomes (y,-x) after 90 degree CCW rotation
	for (unsigned int i = 0; i < blockPositions.size(); i++)
	{
		int tempX = (blockPositions[i].getY() - originY) + originX;
		int tempY = -(blockPositions[i].getX() - originX) + originY;
		blockPositions[i].setX(tempX);
		blockPositions[i].setY(tempY);
	}
}

void Tetramino::rotateCW()
{
	rotation += 90;
	if (rotation == 360)
	{
		rotation = 0;
	}
	int originX = blockPositions[pivotBlockIndex].getX();
	int originY = blockPositions[pivotBlockIndex].getY();
	//A point (x,y) becomes (-y,x) after 90 degree CW rotation
	for (unsigned int i = 0; i < blockPositions.size(); i++)
	{
		int tempX = -(blockPositions[i].getY() - originY) + originX;
		int tempY = (blockPositions[i].getX() - originX) + originY;
		blockPositions[i].setX(tempX);
		blockPositions[i].setY(tempY);
	}
}

void Tetramino::moveRight()
{
	for (auto& blockPosition : blockPositions)
	{
		blockPosition.setX(blockPosition.getX() + texture->getWidth());
	}
}

void Tetramino::moveLeft()
{
	for (auto& blockPosition : blockPositions)
	{
		blockPosition.setX(blockPosition.getX() - texture->getWidth());
	}
}

void Tetramino::moveDown()
{
	for (auto& blockPosition : blockPositions)
	{
		blockPosition.setY(blockPosition.getY() + texture->getHeight());
	}
}

void Tetramino::moveUp()
{
	for (auto& blockPosition : blockPositions)
	{
		blockPosition.setY(blockPosition.getY() + texture->getHeight());
	}
}

void Tetramino::moveBy(int x, int y)
{
	for (auto& blockPosition : blockPositions)
	{
		blockPosition.setX(blockPosition.getX() + x * texture->getWidth());
		blockPosition.setY(blockPosition.getY() + y * texture->getHeight());
	}
}

void Tetramino::draw(int drawBlockBelow)
{
	for (unsigned int i = 0; i < blockPositions.size(); i++)
	{
		int y = blockPositions[i].getY();
		if (y >= drawBlockBelow)
		{
			texture->draw(blockPositions[i].getX(), y);
		}
	}
}

std::random_device randomDevice;
std::minstd_rand randomNumberEngine(randomDevice());
std::uniform_int_distribution<> tetraminoType(1, 7);

Tetramino* Tetramino::getRandomTetramino(unsigned int gridOriginX, unsigned int gridOriginY)
{
	int randomTetramino = tetraminoType(randomNumberEngine);

	Tetramino* tetramino;
	Texture* texture;
	switch (randomTetramino)
	{
	case 1:
		texture = theTextureFactory->Create(".\\media\\blueBlock.bmp");
		tetramino = new Crate(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + texture->getHeight());
		break;
	case 2:
		texture = theTextureFactory->Create(".\\media\\cyanBlock.bmp");
		tetramino = new LeftL(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	case 3:
		texture = theTextureFactory->Create(".\\media\\greenBlock.bmp");
		tetramino = new LeftStep(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	case 4:
		texture = theTextureFactory->Create(".\\media\\orangeBlock.bmp");
		tetramino = new RightL(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	case 5:
		texture = theTextureFactory->Create(".\\media\\pinkBlock.bmp");
		tetramino = new RightStep(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	case 6:
		texture = theTextureFactory->Create(".\\media\\purpleBlock.bmp");
		tetramino  = new Slab(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	case 7:
	default:
		texture = theTextureFactory->Create(".\\media\\redBlock.bmp");
		tetramino = new VictoryStand(0, 0, texture);
		tetramino->setOrigin(gridOriginX + 4 * texture->getWidth(), gridOriginY + 2 * texture->getHeight());
		break;
	}
	return tetramino;
}
