#include "Ticket.h"
#include "Event.h"
#include "Location.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Location l1();
    Ticket t1();
    Event e1();

    int seatNumbers[]{ 1,2,3 };
    Location l2(3, "MetArena", seatNumbers);
    Ticket t2(5, GOLD);
    Event e2("RHCP TOUR", "12-12-2023", "20:00");

    Location l3(l2);
    Ticket t3(t2);
    Event e3(e2);

    Location l4 = l3;
    Ticket t4 = t3;
    Event e4 = e3;

    cin >> l4;
    cin >> t4;
    cin >> e4;

    cout <<  l4;
    cout <<  t4;
    cout <<  e4;

}