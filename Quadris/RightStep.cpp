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
	Tetramino(originX, originY, texture)
{
	blockOffsets[0].setX(0);
	blockOffsets[0].setY(-texture->getHeight());

	blockOffsets[1].setX(texture->getWidth());
	blockOffsets[1].setY(-texture->getHeight());

	blockOffsets[2].setX(-texture->getWidth());
	blockOffsets[2].setY(0);

	blockOffsets[3].setX(0);
	blockOffsets[3].setY(0);
}
