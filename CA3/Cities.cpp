// Daniel Buckley
// X00109141

#include "Cities.h"
#include <iostream>

City::City() {
	city = "";
	coordinates = { 0.0, 0.0 };
	population = 0;
	averageTemp = 0;
}

City::City(string name, double longitude, double latitude, int populationIn, double avg) {
	city = name;
	coordinates = { longitude, latitude };
	population = populationIn;
	averageTemp = avg;
}

// Overwrites the << operator which allows me to
// print the city object easily
ostream& operator<<(ostream& str, const City city) {
	str << city.city << " " << city.coordinates.first  << " " << city.coordinates.second << " " << city.population << " " << city.averageTemp << "\n";
	return str;
}