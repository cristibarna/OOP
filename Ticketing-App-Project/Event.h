#pragma once
#ifndef Event.h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Event
{
	string name = "";
	string date = "";
	string time = "";

	static string COMPANY;

public:

	~Event() {

	}

	Event() {

	}

	Event(string name, string date, string time) {
		this->name = name;
		this->date = date;
		this->time = time;
	}

	Event(Event& e) {
		this->name = e.name;
		this->date = e.date;
		this->time = e.time;
	}

	Event& operator=(Event& e) {
		this->name = e.name;
		this->date = e.date;
		this->time = e.time;
	}

	string getName() {
		return this->name;
	}

	string getDate() {
		return this->date;
	}

	string getTime() {
		return this->time;
	}

	void setName(string name) {
		this->name = name;
	}

	void setDate(string date) {
		this->date = date;
	}

	void setTime(string time) {
		this->time = time;
	}

	static string getCompany() {
		return COMPANY;
	}

	static void setCompany(string company) {
		Event::COMPANY = company;
	}
};

string Event::COMPANY = "DSS";
#endif Event.h

