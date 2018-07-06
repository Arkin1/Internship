#include<iostream>

using namespace std;


template <class T>
constexpr auto threshold = static_cast<T>(0.0000010);

template <class T>
constexpr T absolute(T val)
{
	return val < T{ 0 } ? -val : val;
}

template<class T>
constexpr T evaluate(T a, T b)
{
	return absolute(a - b) <= threshold<T>;
}

template<typename T>
constexpr bool  close_enough(T a, T b)
{
	if (evaluate(a,b))
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
}