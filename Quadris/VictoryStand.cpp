#include "VictoryStand.h"

using namespace std;

VictoryStand::VictoryStand(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, 2, texture)
{
	setOrigin(originX, originY);
}

void VictoryStand::setOrigin(int x, int y)
{
	blockPositions[0].setX(x);
	blockPositions[0].setY(y - texture->getHeight());

	blockPositions[1].setX(x - texture->getWidth());
	blockPositions[1].setY(y);

	blockPositions[2].setX(x);
	blockPositions[2].setY(y);

	blockPositions[3].setX(x + texture->getWidth());
	blockPositions[3].setY(y);
}