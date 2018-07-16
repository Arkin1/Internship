/*#include<iostream>
#include<fstream>
#include<random>
#include<sstream>
#include<string>
#include<map>
using namespace std;

struct InfoObject
{
public:
	char msg[100];

};

class TrainObject
{
public:
	const enum class Direction :int { ARRIVAL, DEPARTURE };

	int train_id;
	Direction direction;
	char time[100];

};

class WarningObject
{
public:
	const enum class Severity :int { NONE, MILD, MEDIUM, HIGH, CRITICAL };

	char msg[100];
	Severity severity;

};

struct Message {
private:
	enum class Type: int {INFORMATION, TRAIN, WARNING } isUsed;


	static Type getType(const string &s)
	{
		if (s == "INFORMATION")  return Type::INFORMATION;
		else if (s == "TRAIN")   return Type::TRAIN;
		else				     return Type::WARNING;
	}

	static WarningObject::Severity getSeverity(const string &s)
	{
		if (s == "none")        return WarningObject::Severity::NONE;
		else if (s == "mild")        return WarningObject::Severity::MILD;
		else if (s == "medium")      return WarningObject::Severity::MEDIUM;
		else if (s == "high")        return WarningObject::Severity::HIGH;
		else    return WarningObject::Severity::CRITICAL;
	}

public:

	union ObjectUnion
	{
		InfoObject auxInfo;
		TrainObject auxTrain;
		WarningObject auxWarning;
	}objectUnion;

	Message() {};

	Message(const InfoObject &info)
	{
		isUsed = Message::Type::INFORMATION;
		objectUnion.auxInfo = info;
	}

	Message(const TrainObject &train)
	{
		isUsed = Message::Type::TRAIN;
		objectUnion.auxTrain = train;
	}

	Message(const WarningObject &warning)
	{
		isUsed = Message::Type::WARNING;
		objectUnion.auxWarning = warning;
	}

	friend istream& operator >> (istream &is, Message &message);

	friend ostream& operator << (ostream &os, const Message &message);
	
};

ostream& operator << (ostream &os, const Message &message)
{
	
	switch (message.isUsed)
	{
	case Message::Type::INFORMATION:
		os << "INFORMATION " << message.objectUnion.auxInfo.msg << '\n';
		break;
	case Message::Type::TRAIN:
		os << "TRAIN " << message.objectUnion.auxTrain.train_id << ", " <<
			((message.objectUnion.auxTrain.direction == TrainObject::Direction::ARRIVAL) ? "arrival" : "departure")
			<< " at " << message.objectUnion.auxTrain.time << '\n';
		break;

	case Message::Type::WARNING:
		const char* severity_values[5] = { "none", "mild", "medium", "high", "critical" };

		os << "WARNING " << message.objectUnion.auxWarning.msg << "(" <<
			severity_values[static_cast<std::underlying_type_t < WarningObject:: Severity 
			>> (message.objectUnion.auxWarning.severity)] << ")\n";

		break;
	}
	return os;
}

istream& operator >> (istream &is, Message &message)
{
	auto directie = TrainObject::Direction::DEPARTURE;
	auto svr = WarningObject::Severity::NONE;

	string str, type, dir, time;
	string msg2;
	getline(is, str);

	istringstream iss(str);
	iss >> type;

	switch (Message::getType(type))
	{
	case Message::Type::INFORMATION:

		iss.get();
		getline(iss, msg2);

		InfoObject obj_info;
		memcpy(obj_info.msg, msg2.c_str(), strlen(msg2.c_str()) + 1);
		memcpy(&message.objectUnion.auxInfo,&obj_info, sizeof(obj_info));

		message.isUsed = Message::Type::INFORMATION;
		break;
	case Message::Type::TRAIN:

		int id;
		iss >> id;

		//,
		iss >> dir;

		iss >> dir;
		if (dir == "arrival")
			directie = TrainObject::Direction::ARRIVAL;
		else
			directie = TrainObject::Direction::DEPARTURE;

		//at
		iss >> time;
		//" "
		iss.get();

		getline(iss, time);

		TrainObject obj_train;
		obj_train.train_id = id;
		obj_train.direction = directie;
		memcpy(obj_train.time, time.c_str(), strlen(time.c_str()) + 1);
		memcpy(&message.objectUnion.auxTrain, &obj_train, sizeof(obj_train));

		message.isUsed = Message::Type::TRAIN;
		break;
	case Message::Type::WARNING:
		iss.get();

		string temp, temp2;
		getline(iss, temp);

		int last_pos = temp.find_last_of("(");
		temp2 = temp.substr(0, last_pos);

		string severity;
		severity = temp.substr(last_pos + 1, temp.size() - last_pos - 2);

		svr = Message::getSeverity(severity);

		WarningObject obj_warning;

		obj_warning.severity = svr;
		memcpy(obj_warning.msg, temp2.c_str(), strlen(temp2.c_str()) + 1);
		memcpy(&message.objectUnion.auxWarning, &obj_warning, sizeof(obj_warning));

		message.isUsed = Message::Type::WARNING;
		break;
	}

	return is;
}



void produce_schedule(const char* name)
{
	ofstream out_file(name);

	out_file << Message{InfoObject{"All is fine in this fine city"} };

	out_file << Message{ TrainObject{ 3, TrainObject::Direction::ARRIVAL,
		"8:0" } };

	out_file << Message{ TrainObject{ 7, TrainObject::Direction::DEPARTURE,
		"10:15" } };

	out_file << Message{ TrainObject{ 2, TrainObject::Direction::ARRIVAL,
		"12:20" } };

	out_file << Message{ WarningObject{ "Please do not litter", WarningObject::Severity::MEDIUM } };
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

	system("pause");

	return 0;
}*/