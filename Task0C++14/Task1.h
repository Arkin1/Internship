#pragma once

#include<exception>

class div_zero_exception : std::exception
{
public:
	const char* what() const throw()
	{
		return "Divide by 0 exception";
	}
};

int integral_div(int num, int denom);