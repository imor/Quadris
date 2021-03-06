#include "RightStep.h"

using namespace std;

/* Shape :-
          ____ ____
         | 1  | 2  |
	 ____|____|____|
	| 3	 | 4  |    
	|____|_+__|

	+ indicates rotation anchor point
*/
RightStep::RightStep(int originX, int originY, Texture* texture) :
	Tetramino(originX, originY, 3, texture)
{
	setOrigin(originX, originY);
}

void RightStep::setOrigin(int x, int y)
{
	blockPositions[0].setX(x);
	blockPositions[0].setY(y - texture->getHeight());

	blockPositions[1].setX(x + texture->getWidth());
	blockPositions[1].setY(y - texture->getHeight());

	blockPositions[2].setX(x - texture->getWidth());
	blockPositions[2].setY(y);

	blockPositions[3].setX(x);
	blockPositions[3].setY(y);
}
