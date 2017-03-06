#pragma once
#include <string>
using namespace std;

class City {
	friend class BinaryTree;
private:
	string city;
	pair<double, double> coordinates;
	int population;
	double averageTemp;
public:
	City();
	City(string, double, double, int, double);
	friend ostream& operator<<(ostream&, const City city);
};
