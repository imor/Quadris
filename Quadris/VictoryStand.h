#ifndef __VSTAND_H__
#define __VSTAND_H__

#include "Tetramino.h"

class VictoryStand : public Tetramino
{
/* Shape :-
          ____
         | 1  |
	 ____|____|____
	| 2	 | 3  | 4  |
	|____|_+__|____|

	+ indicates rotation anchor point
*/
public:
	VictoryStand(int originX, int originY, Texture* texture);
};
#endif //__VSTAND_H__