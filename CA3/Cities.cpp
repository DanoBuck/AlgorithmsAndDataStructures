#include "Cities.h"
#include <iostream>

City::City() {
	city = "";
	// Pair instanciation
	coordinates = { 0.0, 0.0 };
	population = 0;
	averageTemp = 0;
}

City::City(string name, double longitude, double latitude, int populationIn, double avg) {
	city = name;
	// Pair instanciation
	coordinates = { longitude, latitude };
	population = populationIn;
	averageTemp = avg;
}

ostream& operator<<(ostream& str, const City city) {
	str << city.city << " " << city.coordinates.first  << " " << city.coordinates.second << " " << city.population << " " << city.averageTemp << "\n";
	return str;
}