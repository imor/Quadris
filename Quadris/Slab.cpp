#include "Slab.h"

using namespace std;

Slab::Slab(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, texture)
{
	blockOffsets[0].setX(-texture->getWidth());
	blockOffsets[0].setY(0);

	blockOffsets[1].setX(0);
	blockOffsets[1].setY(0);

	blockOffsets[2].setX(texture->getWidth());
	blockOffsets[2].setY(0);

	blockOffsets[3].setX(2 * texture->getWidth());
	blockOffsets[3].setY(0);

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

void Slab::rotateCCW()
{
	Tetramino::rotateCCW();

	switch (rotation)
	{
	case 0:
		origin.setX(origin.getX() - texture->getWidth());
		break;
	case 90:
		origin.setY(origin.getY() - texture->getHeight());
		break;
	case 180:
		origin.setX(origin.getX() + texture->getWidth());
		break;
	case 270:
		origin.setY(origin.getY() + texture->getHeight());
		break;
	}
}

void Slab::rotateCW()
{
	Tetramino::rotateCW();

	switch(rotation)
	{
	case 0:
		origin.setY(origin.getY() - texture->getHeight());
		break;
	case 90:
		origin.setX(origin.getX() + texture->getWidth());
		break;
	case 180:
		origin.setY(origin.getY() + texture->getHeight());
		break;
	case 270:
		origin.setX(origin.getX() - texture->getWidth());
		break;
	}
}
