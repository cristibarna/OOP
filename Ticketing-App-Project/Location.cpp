#include "Location.h"

ostream& operator<<(ostream& out, Location l) {
	out << endl << "No seats: " << l.noSeats;
	out << endl << "Venue name: ";
	if (l.venueName != nullptr) {
		out << l.venueName;
	}
	out << endl;
	out << endl << "Seat number: ";
	for (int i = 0; i < l.noSeats; i++) {
		out << l.seatNumber[i] << " ";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Location& l) {
	cout << endl << "Venue Name: ";
	string buffer;
	in >> buffer;
	l.setZones(buffer.c_str());
	cout << endl << "No seats: ";
	in >> l.noSeats;
	if (l.noSeats < 0)
	{
		cout << endl << "Invalid input. Number of rows and seats should be non-negative.";
		return in;
	}
	if (l.seatNumber != nullptr) {
		delete[] l.seatNumber;
	}
	l.seatNumber = new int[l.noSeats];
	cout << endl << "Seat number: ";
	for (int i = 0; i < l.noSeats; i++) {
		in >> l.seatNumber[i];
	}
	return in;
}