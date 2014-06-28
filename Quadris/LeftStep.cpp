#include "LeftStep.h"

using namespace std;

LeftStep::LeftStep(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, texture)
{
	blockOffsets[0].setX(-texture->getWidth());
	blockOffsets[0].setY(-texture->getHeight());

	blockOffsets[1].setX(0);
	blockOffsets[1].setY(-texture->getHeight());

	blockOffsets[2].setX(0);
	blockOffsets[2].setY(0);

	blockOffsets[3].setX(texture->getWidth());
	blockOffsets[3].setY(0);
}
