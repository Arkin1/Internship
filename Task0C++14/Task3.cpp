/*#include<iostream>
#include<type_traits>
using namespace std;


template <typename T>
constexpr auto threshold = static_cast<T>(0.0000010);

template <typename T>
constexpr T absolute(T val)
{
	return val < T{ 0 } ? -val : val;
}

template<typename T>
constexpr T evaluate(T a, T b)
{
	if (is_floating_point <T> ::value || is_floating_point<T>::value)
	{
		return absolute(a - b) <= threshold<T>;
	}
	else
		return  a==b;
	
}

template<typename T>
constexpr bool  close_enough(T a, T b)
{
	if constexpr (absolute(a - b) <= threshold<T>)
	{
		//cout << "Yes, close enough\n";
		return true;
	}
	else
	{
		//cout << "No, not close enough\n";
		return false;
	}
};

int main()
{
	static_assert(close_enough(3, 3), "");
	static_assert(!close_enough(3, 4), "");
	static_assert(close_enough(3.0f, 10.0f - 7), "");
	static_assert(close_enough(3.0, 1.0 + 2.0), "");




	return 0;
}*/