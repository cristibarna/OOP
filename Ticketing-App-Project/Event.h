#pragma once
#ifndef Event.h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <chrono>
#include <sstream>
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

	char operator[](size_t index) const {
		if (index < name.length()) {
			return name[index];
		}
		return '\0';
	}

	Event operator+(const Event& e) const {
		Event result(name + e.name, date + e.date, time + e.time);
		result.setCompany(COMPANY);
		return result;
	}

	bool isEventValid() const{
		return !name.empty() && !date.empty() && !time.empty();
	}

	friend ostream& operator<<(ostream& out, Event e);
	friend istream& operator>>(istream& in, Event& e);
};        
#endif Event.h

