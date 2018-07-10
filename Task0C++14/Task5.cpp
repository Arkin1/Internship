#include<iostream>
#include<fstream>
#include<random>
#include<sstream>
#include<string>
using namespace std;


struct Message
{
public:

	const enum class Type:int { INFORMATION, TRAIN, WARNING };
	const enum class Direction:int { ARRIVAL, DEPARTURE};
	const enum class Severity:int { NONE, MILD, MEDIUM, HIGH, CRITICAL };

	int train_id;
	Type type;
	Direction direction;
	string msg, time;

	Severity severity;

	friend istream& operator >> (istream &is, Message &message)
	{

		string str, type, dir, time;
		getline(is, str);


		istringstream iss(str);

		iss >> type;

		if (type == "INFORMATION")
		{
			message.type = Message::Type::INFORMATION;
			iss.get();

			getline(iss, message.msg);
		}
		else if (type == "TRAIN")
		{
			message.type = Message::Type::TRAIN;
			iss >> message.train_id;

			//,
			iss >> dir;

			iss >> dir;

			if (dir == "arrival")
				message.direction = Message::Direction::ARRIVAL;
			else
				message.direction = Message::Direction::DEPARTURE;

			//at
			iss >> time;
			//" "
			iss.get();

			getline(iss, message.time);
		}
		else
		{
			message.type = Message::Type::WARNING;

			iss.get();

			string temp;

			getline(iss, temp);

			int last_pos = temp.find_last_of("(");

			message.msg = temp.substr(0, last_pos);

			string severity;

			severity = temp.substr(last_pos + 1, temp.size() - last_pos - 2);

			if (severity == "none") message.severity = Message::Severity::NONE;

			else if (severity == "mild") message.severity = Message::Severity::MILD;

			else if (severity == "medium") message.severity = Message::Severity::MEDIUM;

			else if (severity == "high") message.severity = Message::Severity::HIGH;

			else message.severity = Message::Severity::CRITICAL;



		}

		return is;
	}

	friend ostream& operator << (ostream &os, Message &message)
	{
		const char* severity_values[5] = { "none", "mild", "medium", "high", "critical" };

		if (message.type == Message::Type::INFORMATION)
		{
			os << "INFORMATION " << message.msg << '\n';
		}
		else if (message.type == Message::Type::TRAIN)
		{
			os << "TRAIN " << message.train_id << ", " <<
				((message.direction == Message::Direction::ARRIVAL) ? "arrival" : "departure")
				<< " at " << message.time << '\n';
		}
		else
		{
			os << "WARNING " << message.msg << "(" << 
				severity_values[static_cast<std::underlying_type<Message::Severity>::type>(message.severity) ] << ")\n";
		}

		return os;
	}


};



void produce_schedule(const char* name)
{
	ofstream out_file(name);

	Message m = {0, Message::Type::INFORMATION , Message::Direction::ARRIVAL, 
		"All is fine in this fine city", "8:0", Message::Severity::NONE};


	out_file << m;

	m = { 3, Message::Type::TRAIN , Message::Direction::ARRIVAL,
		"", "8:0", Message::Severity::NONE };

	out_file << m;

	m = { 7, Message::Type::TRAIN , Message::Direction::DEPARTURE,
		"", "10:15", Message::Severity::NONE };

	out_file << m;

	m = { 2, Message::Type::TRAIN , Message::Direction::ARRIVAL,
		"", "12:20", Message::Severity::NONE };

	out_file << m;

	m = { 7, Message::Type::WARNING , Message::Direction::ARRIVAL,
		"Please do not litter", "10:15", Message::Severity::MEDIUM };



	out_file << m;
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