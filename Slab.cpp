#include "Slab.h"

using namespace std;

Slab::Slab(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, 1, texture)
{
	setOrigin(originX, originY);

	wallKickData[0].clear();
	wallKickData[0].push_back(Point(0, 0));
	wallKickData[0].push_back(Point(1, 0));
	wallKickData[0].push_back(Point(-2, 0));
	wallKickData[0].push_back(Point(1, 2));
	wallKickData[0].push_back(Point(-2, -1));

	wallKickData[1].clear();
	wallKickData[1].push_back(Point(0, 0));
	wallKickData[1].push_back(Point(-2, 0));
	wallKickData[1].push_back(Point(1, 0));
	wallKickData[1].push_back(Point(-2, 1));
	wallKickData[1].push_back(Point(1, -2));

	wallKickData[2].clear();
	wallKickData[2].push_back(Point(0, 0));
	wallKickData[2].push_back(Point(-1, 0));
	wallKickData[2].push_back(Point(2, 0));
	wallKickData[2].push_back(Point(-1, -2));
	wallKickData[2].push_back(Point(2, 1));

	wallKickData[3].clear();
	wallKickData[3].push_back(Point(0, 0));
	wallKickData[3].push_back(Point(2, 0));
	wallKickData[3].push_back(Point(-1, 0));
	wallKickData[3].push_back(Point(2, -1));
	wallKickData[3].push_back(Point(-1, 2));
}

void Slab::setOrigin(int x, int y)
{
	blockPositions[0].setX(x - texture->getWidth());
	blockPositions[0].setY(y);

	blockPositions[1].setX(x);
	blockPositions[1].setY(y);

	blockPositions[2].setX(x + texture->getWidth());
	blockPositions[2].setY(y);

	blockPositions[3].setX(x + 2 * texture->getWidth());
	blockPositions[3].setY(y);
}

void Slab::rotateCCW()
{
	Tetramino::rotateCCW();

	for (auto& blockPosition : blockPositions)
	{
		switch (rotation)
		{
			case 0:
				blockPosition.setX(blockPosition.getX() - texture->getWidth());
				break;
			case 90:
				blockPosition.setY(blockPosition.getY() - texture->getHeight());
				break;
			case 180:
				blockPosition.setX(blockPosition.getX() + texture->getWidth());
				break;
			case 270:
				blockPosition.setY(blockPosition.getY() + texture->getHeight());
				break;
		}
	}
}

void Slab::rotateCW()
{
	Tetramino::rotateCW();

	for (auto& blockPosition : blockPositions)
	{
		switch (rotation)
		{
		case 0:
			blockPosition.setY(blockPosition.getY() - texture->getHeight());
			break;
		case 90:
			blockPosition.setX(blockPosition.getX() + texture->getWidth());
			break;
		case 180:
			blockPosition.setY(blockPosition.getY() + texture->getHeight());
			break;
		case 270:
			blockPosition.setX(blockPosition.getX() - texture->getWidth());
			break;
		}
	}
}
