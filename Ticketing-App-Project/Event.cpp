#include "Event.h"

string Event::COMPANY = "DSS";

ostream& operator<<(ostream& out, Event e) {
	out << endl << "Name: " << e.name;
	out << endl << "Date: " << e.date;
	out << endl << "Time: " << e.time;
	return out;
}

istream& operator>>(istream& in, Event& e) {
	cout << endl << "Name: ";
	in >> e.name;
	cout << endl << "Date: ";
	in >> e.date;
	cout << endl << "Time: ";
	in >> e.time;
	return in;
}
