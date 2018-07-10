#include<iostream>
#include<type_traits>
#include<utility>
#include<vector>
#include<set>
using namespace std;

template<class T>
class value_range_iterator  {

	T it;

public:
	value_range_iterator() {}

	value_range_iterator(T iterator) : it(iterator) {}

	T operator*() const { return it; }


	value_range_iterator<T>& operator++()
	{
		++it;

		return *this;
	}
	value_range_iterator<T> operator++(int)
	{
		value_range_iterator<T> range_it(it);

		++it;

		return range_it;
	}

	value_range_iterator<T> & operator--()
	{
		--it;

		return *this;
	}
	value_range_iterator<T> operator--(int)
	{
		value_range_iterator<T> range_it(it);

		--it;

		return range_it;
	}

	bool operator!= (value_range_iterator<T> it)
	{
		return this->it != it.it;
	}



};

template<class T>
class value_range
{
	T a, b;
public:
	value_range() : a(0), b(0) {}
	value_range(T first, T last) : a(first), b(last) {}

	value_range_iterator<T> begin() { return value_range_iterator<T>(a); }

	value_range_iterator<T> end() { return value_range_iterator<T>(b); }

};


template<class T>
auto value_range_from(T& arr)
{
	return value_range(begin(arr), end(arr));
}



/*template<typename T, typename... Types>
constexpr T average(Types... args)
{
	return (... + args) / sizeof...(args);	
}*/


int main()
{
	//static_assert(average<float>(2, 3, 5, 2.2f, 11)>4.6);


	value_range<int> range{ 10, 20 };


	for (auto n : range)
		cout << n <<  ' ';

	cout << '\n';


	int arr[] = { 2,3,5,7,11 };




	for (const auto &val : value_range_from(arr))
	{
		cout << val << ' ';
	}
	cout << '\n';



	return 0;
}