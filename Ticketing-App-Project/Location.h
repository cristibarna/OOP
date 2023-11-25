#pragma once
#ifndef Location.h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Location
{
	int noSeats = 0;
	int noRows = 0;
	char* zones = nullptr;
	int* seatNumber = nullptr;

public:
	
	~Location() {
		if (zones != nullptr) {
			delete[] zones;
		}
		if (seatNumber != nullptr) {
			delete[] seatNumber;
		}
	}

	Location() {

	}

	Location(int noSeats, int noRows, const char* zones, const int* seatNumber) {
		this->noSeats = noSeats;
		this->noRows = noRows;
		if (zones != nullptr) {
			this->zones = new char[strlen(zones) + 1];
			strcpy(this->zones, zones);
		}
		else {
			this->zones = nullptr;
		}
		if (noSeats > 0 && seatNumber != nullptr) {
			this->noSeats = noSeats;
			this->seatNumber = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				this->seatNumber[i] = seatNumber[i];
			}
		}
		else {
			this->noSeats = 0;
			this->seatNumber = nullptr;
		}
	}

	Location(Location& l) {
		this->noSeats = l.noSeats;
		this->noRows = l.noRows;
		if (l.zones != nullptr) {
			this->zones = new char[strlen(l.zones) + 1];
			strcpy(this->zones, l.zones);
		}
		else {
			this->zones = nullptr;
		}
		if (l.noSeats > 0 && l.seatNumber != nullptr) {
			this->noSeats = l.noSeats;
			this->seatNumber = new int[l.noSeats];
			for (int i = 0; i < l.noSeats; i++) {
				this->seatNumber[i] = l.seatNumber[i];
			}
		}
		else {
			this->noSeats = 0;
			this->seatNumber = nullptr;
		}
	}

	Location& operator=(Location& l) {
		if (this == &l)
			return *this;
		if (zones != nullptr) {
			delete[] zones;
		}
		if (seatNumber != nullptr) {
			delete[] seatNumber;
		}
		this->noSeats = l.noSeats;
		this->noRows = l.noRows;
		if (l.zones != nullptr) {
			this->zones = new char[strlen(l.zones) + 1];
			strcpy(this->zones, l.zones);
		}
		else {
			this->zones = nullptr;
		}
		if (l.noSeats > 0 && l.seatNumber != nullptr) {
			this->noSeats = l.noSeats;
			this->seatNumber = new int[l.noSeats];
			for (int i = 0; i < l.noSeats; i++) {
				this->seatNumber[i] = l.seatNumber[i];
			}
		}
		else {
			this->noSeats = 0;
			this->seatNumber = nullptr;
		}
	}

	int getNoSeats() {
		return this->noSeats;
	}

	int getNoRows() {
		return this->noRows;
	}

	char* getZones() {
		if (zones != nullptr)
		{
			char* copy = new char[strlen(zones) + 1];
			strcpy(copy, zones);
			return copy;
		}
		return nullptr;
	}

	int* getSeatNumber() {
		if (seatNumber != nullptr)
		{
			int* copy = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				copy[i] = seatNumber[i];
			}
			return copy;
		}
		else return nullptr;
	}

	void setNoSeats(int noSeats) {
		this->noSeats = noSeats;
	}

	void setNoRows(int noRows) {
		this->noRows = noRows;
	}

	void setZones(const char* zones) {
		if (zones != nullptr) {
			if (this->zones != nullptr) {
				delete[] this->zones;
			}
			this->zones = new char[strlen(zones) + 1];
			strcpy(this->zones, zones);
		}
	}

	void setSeatNumber(const int* seatNumber, int noSeats) {
		if (seatNumber != nullptr && noSeats > 0)
		{
			delete[] this->seatNumber;
			this->seatNumber = new int[noSeats];
			for (int i = 0; i < noSeats; i++) {
				this->seatNumber[i] = seatNumber[i];
			}
			this->noSeats = noSeats;
		}
	}

	friend ostream& operator<<(ostream& out, Location l);
	friend istream& operator>>(istream& in, Location& l);
};
#endif Location.h
