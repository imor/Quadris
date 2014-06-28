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

Tetramino::Tetramino(int originX, int originY, Texture* texture) :
	rotation(0), origin(originX, originY), texture(texture)
{
	for( int i = 0; i < 4; i++)
	{
		blockOffsets.push_back(Point());
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

std::deque<Point> Tetramino::getBlockOffsets() const
{
	return blockOffsets;
}

void Tetramino::rotateCCW()
{
	rotation -= 90;
	if (rotation == -90)
	{
		rotation = 270;
	}
	//A point (x,y) becomes (y,-x) after 90 degree CCW rotation
	for (unsigned int i = 0; i < blockOffsets.size(); i++)
	{
		int tempX = blockOffsets[i].getY();
		int tempY = -blockOffsets[i].getX();
		blockOffsets[i].setX(tempX);
		blockOffsets[i].setY(tempY);
	}
}

void Tetramino::rotateCW()
{
	rotation += 90;
	if (rotation == 360)
	{
		rotation = 0;
	}
	//A point (x,y) becomes (-y,x) after 90 degree CW rotation
	for (unsigned int i = 0; i < blockOffsets.size(); i++)
	{
		int tempX = -blockOffsets[i].getY();
		int tempY = blockOffsets[i].getX();
		blockOffsets[i].setX(tempX);
		blockOffsets[i].setY(tempY);
	}
}

void Tetramino::moveRight()
{
	origin.setX(origin.getX() + texture->getWidth());
}

void Tetramino::moveLeft()
{
	origin.setX(origin.getX() - texture->getWidth());
}

void Tetramino::moveDown()
{
	origin.setY(origin.getY() + texture->getHeight());
}

void Tetramino::moveUp()
{
	origin.setY(origin.getY() - texture->getHeight());
}

void Tetramino::offset(int x, int y)
{
	origin.setX(origin.getX() + x * texture->getWidth());
	origin.setY(origin.getY() + y * texture->getHeight());
}

void Tetramino::draw(int drawBlockBelow)
{
	for (unsigned int i = 0; i < blockOffsets.size(); i++)
	{
		int y = blockOffsets[i].getY() + origin.getY();
		if (y >= drawBlockBelow)
		{
			texture->draw(blockOffsets[i].getX() + origin.getX(), y);
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
