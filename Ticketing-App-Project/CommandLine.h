#pragma once

#include "Event.h";
#include "Location.h";
#include "Ticket.h";

class CommandLine {
	int cnt = 0;
	char* val = nullptr;
	void processFile(const char* fileName);
	void displayMenu();
	void getChoice();

	Event e;
	Location l;
	Ticket t;
public:
	CommandLine(int cnt, char* val[]);

	void processCommandLine(int cnt, char* val[]);
};