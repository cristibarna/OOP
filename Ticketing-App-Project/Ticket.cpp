#include "Ticket.h"

ostream& operator<<(ostream& out, Ticket t) {
	out << endl << "Id: " << t.uniqueId;
	out << endl << "Category: ";
	switch (t.category)
	{
	case BRONZE:
		out << "Bronze";
		break;
	case SILVER:
		out << "Silver";
		break;
	case GOLD:
		out << "Gold";
		break;
	default:
		break;
	}
	return out;
}

istream& operator>>(istream& in, Ticket& t) {
	cout << endl << "Category(0 BRONZE, 1 SILVER, 2 GOLD): ";
	int categoryValue;
	in >> categoryValue;
	switch (categoryValue) {
	case 0:
		t.category = BRONZE;
		break;
	case 1:
		t.category = SILVER;
		break;
	case 2:
		t.category = GOLD;
		break;
	default:
		cout << endl << "Invalid category value. Setting to BRONZE by default.";
		t.category = BRONZE;
	}
	return in;
}
