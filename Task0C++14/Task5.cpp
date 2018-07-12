#include<iostream>
#include<fstream>
#include<random>
#include<sstream>
#include<string>
#include<map>
using namespace std;


struct Object
{
	virtual void print(ostream &os) = 0;
};

struct InfoObject :Object
{
	string msg;

	InfoObject(const string &m) :msg(m) {};

	void print(ostream & os)
	{
		os << "INFORMATION " << msg << '\n';
	}
};

struct TrainObject :Object
{
	const enum class Direction :int { ARRIVAL, DEPARTURE };
	static map<string, Direction> Direction_map;
	int train_id;
	Direction direction;
	string time;

	TrainObject(int id, Direction dir, string tm) : train_id(id), direction(dir), time(tm) {};

	void print(ostream & os)
	{
		os << "TRAIN " << train_id << ", " <<
			((direction == Direction::ARRIVAL) ? "arrival" : "departure")
			<< " at " << time << '\n';
	}
};

struct WarningObject : Object
{
	const enum class Severity :int { NONE, MILD, MEDIUM, HIGH, CRITICAL };
	static map<string, Severity> Severity_map;

	Severity severity;

	string msg;

	WarningObject(string text, Severity sever): msg(text), severity(sever){}

	void print(ostream & os)
	{
		const char* severity_values[5] = { "none", "mild", "medium", "high", "critical" };
		os << "WARNING " << msg << "(" <<
			severity_values[static_cast<std::underlying_type_t<Severity>>(severity)] << ")\n";
	}



};

struct Message
{
public:

	
	Object *o;


	
	friend istream& operator >> (istream &is, Message& message);


	friend ostream& operator << (ostream &os, const Message &message)
	{
		

		message.o->print(os);


		return os;
	}


};

istream& Message::operator >> (istream &is, Message& message)
{

	string str, type, dir, time, msg;
	getline(is, str);


	istringstream iss(str);

	iss >> type;

	if (type == "INFORMATION")
	{
		iss.get();

		getline(iss, msg);

		message.o = new InfoObject(msg);


	}
	else if (type == "TRAIN")
	{
		int train_id;
		string dir, time;

		TrainObject::Direction direction;

		iss >> train_id;

		//,
		iss >> dir;

		iss >> dir;

		direction = TrainObject::Direction_map[dir];

		//at
		iss >> time;
		//" "
		iss.get();

		getline(iss, time);

		message.o = new TrainObject(train_id, direction, time);
	}
	else
	{
		string msg;

		WarningObject::Severity severity;

		iss.get();

		string temp;

		getline(iss, temp);

		int last_pos = temp.find_last_of("(");

		msg = temp.substr(0, last_pos);

		string severity_s;

		severity_s = temp.substr(last_pos + 1, temp.size() - last_pos - 2);

		severity = WarningObject::Severity_map[severity_s];



		message.o = new WarningObject(msg, severity);


	}

	return is;
}


map<string, WarningObject::Severity> WarningObject::Severity_map = { { "none", Severity::NONE },
														 { "mild", Severity::MILD },
														 { "medium", Severity::MEDIUM },
														 { "high", Severity::HIGH },
														 { "critical", Severity::CRITICAL } };

map<string, TrainObject::Direction> TrainObject::Direction_map = { { "arrival", Direction::ARRIVAL },
												           { "departure", Direction::DEPARTURE } };



void produce_schedule(const char* name)
{
	ofstream out_file(name);

	out_file << Message{new InfoObject("All is fine in this fine city") };


	out_file << Message{ new TrainObject(3, TrainObject::Direction::ARRIVAL,"8:0") };

	out_file << Message{ new TrainObject(7, TrainObject::Direction::DEPARTURE,"10:15") };

	out_file << Message{ new TrainObject(2, TrainObject::Direction::ARRIVAL,"12:20") };

	out_file << Message{ new WarningObject("Please do not litter",WarningObject::Severity::MEDIUM) };
}


void consume(Message &message)
{
	cout << message;
}



int main()
{
	produce_schedule("sched.txt");
	// this interface has been imposed by your architects
	
	ifstream schedule{ "sched.txt" };
	for (Message msg; schedule >> msg; )
		consume(msg);




	return 0;
}