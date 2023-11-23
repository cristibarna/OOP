#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>;
#include<string>;
using namespace std;
class Ticket
{
	int uniqueId = 0;
	string category = "";

	void displayTicket() const;

	static Ticket generateTicke(const string& category);
};

