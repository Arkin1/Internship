#include<iostream>
#include<type_traits>
#include<utility>
using namespace std;



template<typename T, typename... Types>
constexpr  T average(Types... args)
{

	int numArgs = sizeof...(args);

	T total = 0;

	const T dummy[] =  { (total+= args)... };

	return total / numArgs;

	
}

int main()
{
	static_assert(average<float>(2, 3, 5, 2.2f, 11) >4.6, "");

	return 0;
}