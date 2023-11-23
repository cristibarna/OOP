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
	string zones = "";
	int* seatNumber = nullptr;

public:
	int getNoSeats() {
		return this->noSeats;
	}

	int getNoRows() {
		return this->noRows;
	}

	string getZones() {
		return this->zones;
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

	void setZones(string zones) {
		this->zones = zones;
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
};

#endif Location.h
