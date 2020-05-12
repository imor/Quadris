#ifndef __RIGHTSTEP_H__
#define __RIGHTSTEP_H__

#include "Tetramino.h"

class RightStep : public Tetramino
{
/* Shape :-
          ____ ____
         | 1  | 2  |
	 ____|____|____|
	| 3	 | 4  |    
	|____|_+__|

	+ indicates rotation anchor point
*/
public:
	void setOrigin(int x, int y);
	RightStep(int originX, int originY, Texture* texture);
};
#endif //__RIGHTSTEP_H__