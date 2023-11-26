#pragma once
#ifndef Location.h
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Location
{
	int noSeats = 0;
	char* venueName = nullptr;
	int* seatNumber = nullptr;

public:
	
	~Location() {
		if (venueName != nullptr) {
			delete[] venueName;
		}
		if (seatNumber != nullptr) {
			delete[] seatNumber;
		}
	}

	Location() {

	}

	Location(int noSeats, const char* venueName, const int* seatNumber) {
		this->noSeats = noSeats;
		if (venueName != nullptr) {
			this->venueName = new char[strlen(venueName) + 1];
			strcpy(this->venueName, venueName);
		}
		else {
			this->venueName = nullptr;
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
		if (l.venueName != nullptr) {
			this->venueName = new char[strlen(l.venueName) + 1];
			strcpy(this->venueName, l.venueName);
		}
		else {
			this->venueName = nullptr;
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
		if (venueName != nullptr) {
			delete[] venueName;
		}
		if (seatNumber != nullptr) {
			delete[] seatNumber;
		}
		this->noSeats = l.noSeats;
		if (l.venueName != nullptr) {
			this->venueName = new char[strlen(l.venueName) + 1];
			strcpy(this->venueName, l.venueName);
		}
		else {
			this->venueName = nullptr;
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

	char* getVenueName() {
		if (venueName != nullptr)
		{
			char* copy = new char[strlen(venueName) + 1];
			strcpy(copy, venueName);
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


	void setVenueName(const char* venueName) {
		if (venueName != nullptr) {
			if (this->venueName != nullptr) {
				delete[] this->venueName;
			}
			this->venueName = new char[strlen(venueName) + 1];
			strcpy(this->venueName, venueName);
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

	bool seatNumberExists(int seatNumber) {
		if (seatNumber < 1 || seatNumber > noSeats) {
			return false;
		}
		for (int i = 0; i < noSeats; i++) {
			if (this->seatNumber[i] == seatNumber) {
				return true;
			}
		}
		return false;
	}

	bool isSeatAvailable(int seatNumber) const {
		if (seatNumber >= 1 && seatNumber <= noSeats) {
			if (this->seatNumber != nullptr) {
				for (int i = 0; i < noSeats; i++) {
					if (this->seatNumber[i] == seatNumber) {
						return false;
					}
				}
			}
			return true;
		}
		else {
			return false;
		}
	}

	Location operator++() {
		this->noSeats++;
		return *this;
	}

	Location operator--() {
		this->noSeats--;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Location l);
	friend istream& operator>>(istream& in, Location& l);
};
#endif Location.h
