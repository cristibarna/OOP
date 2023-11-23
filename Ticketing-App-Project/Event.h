#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Event
{
	string name = "";
	string date = "";
	string time = "";

public:
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
};

