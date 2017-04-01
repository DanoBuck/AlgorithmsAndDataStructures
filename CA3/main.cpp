#include <iostream>
#include "Cities.h"
#include "BinaryTree.h"
#include <cstdio>
#include <ctime>
#include <chrono>
using namespace std;

string existsInTree(bool);

int main() {
	clock_t startcputime = std::clock();
	double cpu_duration = 0;

	City city1 = City("DUBLIN", 53.349805, -6.26031, 1000000, 10.5);
	City city2 = City("GALWAY", 53.270668, -9.056791, 30, 10);
	City city3 = City("CORK", 51.896892, -8.486316, 50000, 10.5);
	City city4 = City("SLIGO", 54.276610, -8.476089, 1000000, 10.5);
	City city5 = City("DONEGAL", 54.653827, -8.109614, 1200, 10.5);
	City city6 = City("DUBLIN", 53.349805, -6.26031, 1000000, 10.5);
	City city7 = City("LIMERICK", 52.668020, -8.630498, 1000000, 10.5);
	City city8 = City("ORLANDO", 28.538335, -81.379236, 500000, 10.5);
	City city9 = City("CALIFORNIA", 36.778261, -119.417932, 500000, 10.5);

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	BinaryTree newTree = BinaryTree();
	newTree.insert(city1);
	newTree.insert(city2);
	newTree.insert(city3);
	newTree.insert(city4);
	newTree.insert(city5);
	newTree.insert(city6);
	newTree.insert(city7);
	newTree.insert(city8);
	newTree.insert(city9);

	cout << "**********Pre Order**********\n";
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	newTree.printPreOrder(newTree.getRoot());
	cout << "\nTree Pre-Order Print Finished in " << cpu_duration << " seconds [CPU Clock] \n";

	//cout << "\n**********In Order**********\n";
	//newTree.printInOrder(newTree.getRoot());

	//cout << "\n**********Post Order**********\n";
	//newTree.printPostOrder(newTree.getRoot());

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	cout << "\nHeight of this tree is: " << newTree.height() << "\n";
	cout << "\nTree Height Finished in " << cpu_duration << " seconds [CPU Clock] \n\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	cout << "Searching for  53.349805, -6.26031: " << existsInTree(newTree.searchByCoordinate({ 53.349805, -6.26031 })) << "\n";
	cout << "Searching for  34111111198, 6.2603: " << existsInTree(newTree.searchByCoordinate({ 34111111198, 6.2603 })) << "\n";
	cout << "Searching for Galway: " << existsInTree(newTree.searchByName("Galway")) << "\n";
	cout << "Searching for sky: " << existsInTree(newTree.searchByName("sky")) << "\n";
	cout << "\nTree Searches Finished in " << cpu_duration << " seconds [CPU Clock] \n\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	cout << "\nDistance from Dublin to California is: " << newTree.calculateDistance({ 53.349805, -6.26031 }, { 36.778261, -119.417932 }) << " KM\n";
	cout << "Distance from Dublin to Galway is: " << newTree.calculateDistance({ 53.349805, -6.26031 }, { 53.270668, -9.056791 }) << " KM\n";
	cout << "\nTree Distances Finished in " << cpu_duration << " seconds [CPU Clock] \n\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	cout << "\nDeleting Cork by name: " << existsInTree(newTree.deleteByName("cork")) << "\n";
	cout << "Deleting Galway by 53.270668, -9.056791: " << existsInTree(newTree.deleteByCoordinatesHelper({ 53.270668, -9.056791 })) << "\n";
	cout << "Deleting Dublin by coordinates 53.349805, -6.26031: " << existsInTree(newTree.deleteByCoordinatesHelper({ 53.349805, -6.26031 })) << "\n";
	cout << "Deleting City which doesn't exist by coordinates 0, 0: " << existsInTree(newTree.deleteByCoordinatesHelper({ 0, 0 })) << "\n";
	cout << "Deleting California by name and coordinates: " << existsInTree(newTree.deleteByNameAndCoordinates("CALIFORNia", { 36.778261, -119.417932 })) << "\n";
	cout << "Deleting City which doesn't exist by name: " << existsInTree(newTree.deleteByName("assddsds")) << "\n";
	cout << "\nTree Deletes Finished in " << cpu_duration << " seconds [CPU Clock] \n\n";
	cout << "\n**********In Order**********\n";
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	newTree.printInOrder(newTree.getRoot());
	cout << "\nTree In-Order Print Finished in " << cpu_duration << " seconds [CPU Clock] \n";

	cout << "\n";
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	newTree.printAllRecordsInDistance({ 53.349805, -6.26031 }, 10000);
	cout << "\nFinished in " << cpu_duration << " seconds [CPU Clock] \n";

	system("pause");
	return 0;
}

string existsInTree(bool exists) {
	if (exists) {
		return "Yes";
	}
	else {
		return "No";
	}
}