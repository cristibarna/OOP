#pragma once
#ifndef Ticket.h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>;
#include<string>;
using namespace std;
enum Category {BRONZE, SILVER, GOLD};

class Ticket
{
	const int uniqueId = 0;
	Category category = Category::BRONZE;

public:

	~Ticket() {

	}

	Ticket() {

	}

	Ticket(int uniqueId, Category category) : uniqueId(uniqueId) {
		this->category = category;
	}

	Ticket(Ticket& t) : uniqueId(t.uniqueId){
		this->category = t.category;
	}

	Ticket& operator=(Ticket& t) {
		this->category = t.category;
	}

	int getId() {
		return this->uniqueId;
	}

	Category getCategory() {
		return this->category;
	}

	void setCategory(Category category) {
		this->category = category;
	}
};
#endif Ticket.h
