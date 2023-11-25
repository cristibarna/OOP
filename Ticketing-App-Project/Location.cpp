#include "Location.h"

ostream& operator<<(ostream& out, Location l) {
	out << endl << "No seats: " << l.noSeats;
	out << endl << "No rows: " << l.noRows;
	out << endl << "Zones: ";
	if (l.zones != nullptr) {
		out << l.zones;
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
	cout << endl << "Zones: ";
	string buffer;
	in >> buffer;
	l.setZones(buffer.c_str());
	cout << endl << "No rows: ";
	in >> l.noRows;
	cout << endl << "No seats: ";
	in >> l.noSeats;
	if (l.noRows < 0 || l.noSeats < 0)
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