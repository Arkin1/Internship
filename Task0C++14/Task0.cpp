#include<iostream>
#include<string>
#include<algorithm>

/*
std::string ltrim(std::string str)
{
	int pos = 0;
	while (pos < str.size() && isspace((*(str.begin() + pos))))
	{
		++pos;


	}

	return str.substr(pos);
}

std::string rtrim(std::string str)
{

	int pos = 0;
	while (pos < str.size()  && isspace((*(str.rbegin() + pos))))
	{
		++pos;
	}

	return str.substr(0, str.size()-pos);
}

std::string trim(std:: string str)
{
	return ltrim(rtrim(str));
}
*/

/*
std::string restriction = " \f\n\r\t\v";

std::string ltrim(std::string str)
{
	size_t pos = str.find_first_not_of(restriction);

	if (pos == std::string::npos)
		return "" ;

	return str.substr(pos);
}

std::string rtrim(std::string str)
{

	size_t pos = str.find_last_not_of(restriction);

	if (pos == std::string::npos)
		return "";

	return str.substr(0,pos+1);
}

std::string trim(std::string str)
{
	return ltrim(rtrim(str));
}
*/

/*std::string restriction = " \f\n\r\t\v";

std::string ltrim(std::string str)
{
	size_t pos = str.find_first_not_of(restriction);

	if (pos == std::string::npos)
		return "";

	return str.erase(0,pos);
}

std::string rtrim(std::string str)
{

	size_t pos = str.find_last_not_of(restriction);

	if (pos == std::string::npos)
		return "";

	return str.erase(pos+1);
}

std::string trim(std::string str)
{
	return ltrim(rtrim(str));
}
*/



std::string ltrim(std::string str)
{
	auto it = std::find_if(str.begin(), str.end(), [](char c) { return !isspace(c);  });

	if (it == str.end())
		return "";



	return str.substr(it-str.begin());
}

std::string rtrim(std::string str)
{

	auto it = std::find_if(str.rbegin(), str.rend(), [](char c) { return !isspace(c);  });

	if (it == str.rend())
		return "";

	return str.substr(0, str.size() - (it - str.rbegin()));
}

std::string trim(std::string str)
{
return ltrim(rtrim(str));
}