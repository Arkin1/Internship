#include<iostream>
#include<vector>
#include<typeinfo>
#include<memory>
using namespace std;

class whatever_cast_exception : public exception
{
public:
	const char* what() const throw() override 
	{
		return "bad whatever cast";
	}
};

class whatever
{
private:

	struct Iplaceholder
	{
		virtual const type_info& type() const = 0;
	};

	shared_ptr<Iplaceholder> ptr;

	template<typename T>
	struct placeholder : public Iplaceholder
	{
		T value;

		placeholder(const T& v) : value(v) {}



		const type_info& type() const override
		{
			return typeid(value);

		}
	};

public:

	whatever()
	{
		ptr = nullptr;
	}

	template<typename T>
	whatever(const T &el)
	{
		ptr = shared_ptr<Iplaceholder>(new placeholder<T>(el));
	}


	bool hasValue()
	{
		return ptr != nullptr;
	}

	template<typename T>
	friend T whatever_cast(const whatever&);

	const type_info& type() const
	{
		return ptr->type();
	}
};
template<typename T>
T whatever_cast(const whatever &we)
{
	
	if (typeid(T) != we.type())
		throw whatever_cast_exception();

	return dynamic_pointer_cast<whatever::placeholder<T>>(we.ptr)->value;
}

struct Installer
{
	virtual void install(whatever) = 0;
	virtual ~Installer() = default;
};

struct DemoInstaller : public Installer
{
	void install(whatever we) override
	{
		if (typeid(string) == we.type() || typeid(double) == we.type()
			|| typeid(int) == we.type() || typeid(float) == we.type())
				cout << we.type().name() <<"\n";
	}

};

vector<whatever> get_new_features()
{
	return vector<whatever>
	{
		    shared_ptr<Installer>(new DemoInstaller),
			string("I love my instructor"),
			3,
			3.14159,
			shared_ptr<Installer>(new DemoInstaller)
	};
}

void install(vector<whatever> v)
{
	
	auto inst = whatever_cast<shared_ptr<Installer>>(v.front()) /* as shared_ptr<Installer> */;
	for (auto p = next(begin(v)); p != end(v); ++p)
		inst->install(*p);
	
}

int main()
{
	install(get_new_features());


	return 0;
}