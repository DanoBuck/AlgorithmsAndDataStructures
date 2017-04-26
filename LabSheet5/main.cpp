#include <iostream>
using namespace std;

int minDistance(int[], bool[]);
void printDistances(int[], int);
void dijkstraToEveryOtherNode(int[8][8], int);
void dijkstraBetweenTwoPoints(int [8][8], int, int);
char getLetter(int);

int main() {

	// Define the graph as seen on the labsheet
	int graph[8][8] = {
	/* A = 0 */	{0, 6, 0, 8, 4, 0, 0, 0},
	/* B = 1 */ {6, 0, 6, 0, 2, 4, 0, 1},
	/* C = 2 */ {0, 6, 0, 0, 0, 0, 3, 0},
	/* D = 3 */ {8, 0, 0, 0, 0, 0, 7, 0},
	/* E = 4 */ {4, 2, 0, 0, 0, 0, 0, 0},
	/* F = 5 */ {0, 4, 0, 0, 0, 0, 5, 3},
	/* G = 6 */ {0, 0, 3, 7, 0, 5, 0, 0},
	/* H = 7 */ {0, 1, 0, 0, 0, 3, 0, 0}
	};

	dijkstraToEveryOtherNode(graph, 0);
	cout << "\n";
	dijkstraBetweenTwoPoints(graph, 0, 7);

	cout << "\n";
	dijkstraToEveryOtherNode(graph, 4);
	cout << "\n";
	dijkstraBetweenTwoPoints(graph, 4, 7);

	system("pause");
	return 0;
}

/***************************************************************************************

*    Usage: Used
*    Title: Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
*    Date: 27/04/2017
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
int minDistance(int distances[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < 8; i++){
		if (sptSet[i] == false && distances[i] <= min) {
			min = distances[i];
			min_index = i;
		}
	}
	return min_index;
}

void printDistances(int distances[], int start)
{
	cout << "Vertex \tDistance from Source\n";
	for (int i = 0; i < 8; i++) {
		if (i != start) {
			cout << "   " << getLetter(i) << " \t   " << distances[i] << "\n";
		}
	}
}

char getLetter(int index) {
	if (index == 0) {
		return 'A';
	}
	else if (index == 1) {
		return 'B';
	}
	else if (index == 2) {
		return 'C';
	}
	else if (index == 3) {
		return 'D';
	}
	else if (index == 4) {
		return 'E';
	}
	else if (index == 5) {
		return 'F';
	}
	else if (index == 6) {
		return 'G';
	}
	else if (index == 7) {
		return 'H';
	}
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
*    Date: 27/04/2017
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
void dijkstraToEveryOtherNode(int graph[8][8], int start)
{
	cout << "*****Shortest path from " << getLetter(start) << " to every other node*****\n";
	int distances[8];

	bool processed[8];

	for (int i = 0; i < 8; i++)
		distances[i] = INT_MAX, processed[i] = false;

	distances[start] = 0;

	for (int i = 0; i < 8 - 1; i++)
	{
		int minDist = minDistance(distances, processed);
		processed[minDist] = true;

		for (int j = 0; j < 8; j++) {
			if (!processed[j] && graph[minDist][j] && distances[minDist] != INT_MAX
				&& distances[minDist] + graph[minDist][j] < distances[j]) {
				distances[j] = distances[minDist] + graph[minDist][j];
			}
		}
	}
	printDistances(distances, start);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
*    Date: 27/04/2017
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
void dijkstraBetweenTwoPoints(int graph[8][8], int start, int end) {
	cout << "*****Shortest path from one node to another*****\n";
	int distances[8];

	bool processed[8];

	for (int i = 0; i < 8; i++)
		distances[i] = INT_MAX, processed[i] = false;

	distances[start] = 0;

	for (int i = 0; i < 8 - 1; i++)
	{
		int minDist = minDistance(distances, processed);
		processed[minDist] = true;

		for (int j = 0; j < 8; j++) {
			if (!processed[j] && graph[minDist][j] && distances[minDist] != INT_MAX
				&& distances[minDist] + graph[minDist][j] < distances[j]) {
				distances[j] = distances[minDist] + graph[minDist][j];
			}
		}
	}

	cout << "Distance from " << getLetter(start) << " to " << getLetter(end) << " is " << distances[end] << "\n";
}