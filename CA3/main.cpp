// Daniel Buckley
// X00109141

#include <iostream>
#include "Cities.h"
#include "BinaryTree.h"
#include <cstdio>
#include <ctime>
#include <chrono>
using namespace std;

string existsInTree(bool);

int main() {
	// CPU Clock
	clock_t startcputime = std::clock();
	double cpu_duration = 0;

	// Wall Time Clock
	auto wcts = std::chrono::system_clock::now();
	
	City city1 = City("DUBLIN", 53.349805, -6.26031, rand() % 5000000, rand() % 50);
	City city2 = City("GALWAY", 53.270668, -9.056791, rand() % 5000000, rand() % 50);
	City city3 = City("CORK", 51.896892, -8.486316, rand() % 5000000, rand() % 50);
	City city4 = City("SLIGO", 54.276610, -8.476089, rand() % 5000000, rand() % 50);
	City city5 = City("DONEGAL", 54.653827, -8.109614, rand() % 5000000, rand() % 50);
	City city6 = City("DUBLIN", 53.349805, -6.26031, rand() % 5000000, rand() % 50);
	City city7 = City("LIMERICK", 52.668020, -8.630498, rand() % 5000000, rand() % 50);
	City city8 = City("ORLANDO", 28.538335, -81.379236, rand() % 5000000, rand() % 50);
	City city9 = City("CALIFORNIA", 36.778261, -119.417932, rand() % 5000000, rand() % 50);
	City city10 = City("BELFAST", 54.5973, -5.9301, rand() % 5000000, rand() % 50);
	City city11 = City("NEW YORK", 40.730610, -73.935242, rand() % 5000000, rand() % 50);
	City city12 = City("TOKYO", 35.652832, 139.839478, rand() % 5000000, rand() % 50);
	City city13 = City("TORONTO", 43.650, -79.380, rand() % 5000000, rand() % 50);
	City city14 = City("LIVERPOOL", 53.419824, -3.0509294, rand() % 5000000, rand() % 50);
	City city15 = City("BERLIN", 52.5072111, 13.1459636, rand() % 5000000, rand() % 50);

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
	newTree.insert(city10);
	newTree.insert(city11);
	newTree.insert(city12);
	newTree.insert(city13);
	newTree.insert(city14);
	newTree.insert(city15);
	cout << "*******************Tree Insertions********************\n";
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	std::chrono::duration<double> wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "Insertion into the tree " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Insertion into the tree " << wctduration.count() << " seconds [Wall Clock]\n\n";

	cout << "*******************Pre Order*******************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	newTree.printPreOrder(newTree.getRoot());
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree Pre-Order Print Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree Pre-Order Print Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Tree Height********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "Height of this tree is: " << newTree.height() << "\n";
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree Height Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree Height Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Searching by coordinates********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "Searching for  53.349805, -6.26031: " << existsInTree(newTree.searchByCoordinate({ 53.349805, -6.26031 })) << "\n";
	cout << "Searching for  34111111198, 6.2603: " << existsInTree(newTree.searchByCoordinate({ 34111111198, 6.2603 })) << "\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree coordinates Searches Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree coordinates Searches Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Searching by city name********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "Searching for Galway: " << existsInTree(newTree.searchByName("Galway")) << "\n";
	cout << "Searching for sky: " << existsInTree(newTree.searchByName("sky")) << "\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree names Searches Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree names Searches Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "\n********************Deletions by city name********************\n";
	cout << "Deleting Cork by name: " << existsInTree(newTree.deleteByName("cork")) << "\n";
	cout << "Deleting Orlando by name: " << existsInTree(newTree.deleteByName("orlando")) << "\n";
	cout << "Deleting City which doesn't exist by name: " << existsInTree(newTree.deleteByName("assddsds")) << "\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree Deletes for Deletions by city name Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree Deletes for Deletions by city name Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Deletions by coordinates********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "Deleting Galway by 53.270668, -9.056791: " << existsInTree(newTree.deleteByCoordinates({ 53.270668, -9.056791 })) << "\n";
	cout << "Deleting Dublin by 53.349805, -6.26031: " << existsInTree(newTree.deleteByCoordinates({ 53.349805, -6.26031 })) << "\n";
	cout << "Deleting California by 36.778261, -119.417932: " << existsInTree(newTree.deleteByCoordinates({ 36.778261, -119.417932 })) << "\n";
	cout << "Deleting City which doesn't exist by coordinates 0, 0: " << existsInTree(newTree.deleteByCoordinates({ 0, 0 })) << "\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree Deletes for Deletions by coordinates Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree Deletes for Deletions by coordinates Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Deletions by city name and coordinates********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	cout << "Deleting Belfast by name and coordinates: " << existsInTree(newTree.deleteByNameAndCoordinates("BELFAST", { 54.5973, -5.9301 })) << "\n";
	cout << "Deleting Donegal by name and coordinates: " << existsInTree(newTree.deleteByNameAndCoordinates("donegal", { 54.653827, -8.109614 })) << "\n";
	cout << "Deleting City which doesn't exist by name and coordinates: " << existsInTree(newTree.deleteByNameAndCoordinates("AnyCity", { 0, -0 })) << "\n";

	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree Deletes for Deletions by city name and coordinates Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree Deletes for Deletions by city name and coordinates Finished in " << wctduration.count() << " seconds [Wall Clock]\n";
	
	cout << "\n********************In Order********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	newTree.printInOrder(newTree.getRoot());
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nTree In-Order Print Finished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Tree In-Order Print Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************Distances from a given point (Dublin) under a given amount of KM's********************\n";
	startcputime = std::clock();
	wcts = std::chrono::system_clock::now();
	newTree.printAllRecordsInDistance({ 53.349805, -6.26031 }, 10000);
	cpu_duration = (clock() - startcputime) / (double)CLOCKS_PER_SEC;
	wctduration = (std::chrono::system_clock::now() - wcts);
	cout << "\nFinished in " << cpu_duration << " seconds [CPU Clock] \n";
	cout << "Finished in " << wctduration.count() << " seconds [Wall Clock]\n";

	cout << "\n********************End of program********************\n";
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