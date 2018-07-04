#include "Task1.h"



std::pair<int,bool> integral_div(int num, int denom)
{
	
	if (denom == 0)
		return { -1,true };


	return { num / denom, false };

}
