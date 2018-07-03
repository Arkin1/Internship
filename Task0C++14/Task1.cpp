#include "Task1.h"

int integral_div(int num, int denom)
{
	
	if (denom == 0)
		throw div_zero_exception();

	return num / denom;

}
