#include<iostream>
#include<chrono>
#include <ratio>
#include<thread>
#include<string>
#include<map>
#include"Task1.h"

using namespace std;
using namespace chrono;

/*template <class F, class ... Args>
auto test(F f, Args &&... args) -> pair<decltype(f(std::forward<Args>(args)...)), std::chrono::high_resolution_clock::duration> {
	auto pre = high_resolution_clock::now();
	auto res = f(std::forward<Args>(args)...);
	auto post = high_resolution_clock::now();
	return make_pair(res, post - pre);
}

template <int N>
string::size_type speed_test_trim() {
	auto n = string::size_type();
	for (int i = 0; i != N; ++i)
		n += trim("  I love my instructor  ").size();
	return n;
}



int correctness_test_ltrim() {
	int failures = 0;
	if (!("I love my instructor" == ltrim("I love my instructor"))) ++failures;
	if (!("I love my instructor" == ltrim("   I love my instructor"))) ++failures;
	if (!("I love my instructor  " == ltrim("I love my instructor  "))) ++failures;
	if (!("I love my instructor  " == ltrim(" I love my instructor  "))) ++failures;
	if (!("" == ltrim(""))) ++failures;
	if (!("" == ltrim("  "))) ++failures;
	return failures;
}

int correctness_test_rtrim() {
	int failures = 0;
	if (!("I love my instructor" == rtrim("I love my instructor"))) ++failures;
	if (!("   I love my instructor" == rtrim("   I love my instructor"))) ++failures;
	if (!("I love my instructor" == rtrim("I love my instructor  "))) ++failures;
	if (!(" I love my instructor" == rtrim(" I love my instructor  "))) ++failures;
	if (!("" == rtrim(""))) ++failures;
	if (!("" == rtrim("  "))) ++failures;
	return failures;
}

int correctness_test_trim() {
	int failures = 0;
	if (!("I love my instructor" == trim("I love my instructor"))) ++failures;
	if (!("I love my instructor" == trim("   I love my instructor"))) ++failures;
	if (!("I love my instructor" == trim("I love my instructor  "))) ++failures;
	if (!("I love my instructor" == trim(" I love my instructor  "))) ++failures;
	if (!("" == trim(""))) ++failures;
	if (!("" == trim("  "))) ++failures;
	return failures;
}*/


int mainmain()
{
	/*cout << correctness_test_ltrim() << "\n";
	cout << correctness_test_rtrim() << "\n";
	cout << correctness_test_trim() << "\n";

	enum { N = 1000000 };
	auto res = test(speed_test_trim<N>);
	cout << "Speed test took " << std::chrono::duration_cast<std::chrono::microseconds>(res.second).count()
		<< " us to perform " << N << " trim() calls" << endl;*/


	
	/*if (int num, denom; cin >> num >> denom)
	{
		if (const auto& [value,error] = integral_div(num, denom); !error)
			cout << value << endl;
		else
			cerr << "Division by zero\n";
	}*/

	map<string, int> mp;

	for (int i = 0; i <= 9; ++i)
	{
		mp.insert({ string("abc") + (char)(i+'0'), i });
	}


	for (const auto&[key, value] : mp)
	{
		cout << key << " " << value << "\n";
	}

	return 0;
}