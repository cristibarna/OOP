#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Product
{
	int id;
	char* name;
	char* description;
	double price;
	double* priceHistory;
	int priceHistorySize = 1;

public:
	Product(int id, const char* name, const char* description, double price, const double* priceHistory)
	{
		this->id = id;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
		this->price = price;
		this->priceHistory = new double[priceHistorySize];
		for (int i = 0; i < priceHistorySize; i++)
			this->priceHistory[i] = priceHistory[i];
	}

	Product(const Product& p)
	{
		this->id = p.id;
		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);
		this->description = new char[strlen(p.description) + 1];
		strcpy(this->description, p.description);
		this->price = p.price;
		this->priceHistory = new double[p.priceHistorySize];
		for (int i = 0; i < p.priceHistorySize; i++)
		{
			this->priceHistory[i] = p.priceHistory[i];
		}
	}

	void setId(int id)
	{
		this->id = id;
	}

	void setName(const char* name)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setDescription(const char* description)
	{
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
	}

	void setPrice(const double* priceHistory, double price)
	{
		priceHistorySize++;
		double* copy = new double[priceHistorySize];
		for (int i = 0; i < priceHistorySize - 1; i++)
			copy[i] = priceHistory[i];
		copy[priceHistorySize - 1] = price;
		delete[] priceHistory;
		this->priceHistory = copy;
		this->price = price;
	}

	int getId()
	{
		return this->id;
	}

	char* getName()
	{
		char* copy = new char[strlen(this->name) + 1];
		strcpy(copy, this->name);
		return copy;
	}

	char* getDescription()
	{
		char* copy = new char[strlen(this->description) + 1];
		strcpy(copy, this->description);
		return copy;
	}

	double getPrice()
	{
		return this->price;
	}

	double* getPriceHistory()
	{
		return this->priceHistory;
	}

	double getPriceAverage()
	{
		double sum = 0;
		for (int i = 0; i < priceHistorySize; i++)
		{
			sum += priceHistory[i];
		}
		return sum / priceHistorySize;
	}

	~Product()
	{
		delete[] this->name;
		delete[] this->description;
		delete[] this->priceHistory;
	}

	friend istream& operator>>(istream& in, Product& p);
	friend ostream& operator<<(ostream& out, Product& p);
};

istream& operator>>(istream& in, Product& p)
{
	string buffer;
	cout << "Enter Id: ";
	in >> p.id;
	cout << "Enter Name: ";
	in >> buffer;
	p.setName(buffer.c_str());
	cout << "Enter Description: ";
	in >> buffer;
	p.setDescription(buffer.c_str());
	cout << "Enter Price: ";
	in >> p.price;
	return in;
}

ostream& operator<<(ostream& out, Product& p)
{
	out << "The product id is: " << p.getId() << endl;
	out << "The product name is: " << p.getName() << endl;
	out << "The product description is: " << p.getDescription() << endl;
	out << "The product price is: " << p.getPrice() << endl;
	return out;
}

int main()
{
	double prices[] = { 100, 120, 150 };
	Product p1(1, "First product", "First description", 120, prices);
	Product p2(p1);
	cout << p2.getId() << endl;
	cout << p2.getName() << endl;
	cout << p2.getDescription() << endl;
	cout << p2.getPrice() << endl;
	cin >> p2;
	cout << p2;
}