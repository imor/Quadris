#ifndef __LEFTSTEP_H__
#define __LEFTSTEP_H__

#include "Tetramino.h"

class LeftStep : public Tetramino
{
/* Shape :-
     ____ ____
    | 1  | 2  |
	|____|____|____
		 | 3  | 4  |
	     |_+__|____|

	+ indicates rotation anchor point
*/
public:
	LeftStep(int originX, int originY, Texture* texture);
};

#endif //__LEFTSTEP_H__