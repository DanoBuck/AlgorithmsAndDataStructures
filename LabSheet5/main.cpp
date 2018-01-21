#include <iostream>
using namespace std;

int minDistance(int[], bool[]);
void printDistances(int[], int, int[], char*);
void dijkstraToEveryOtherNode(int[8][8], int, char*);
void dijkstraBetweenTwoPoints(int [8][8], int, int, char*);
char getLetter(char*, int);
void printPath(int[], int, char*);

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

	char letters[] = { 'A','B','C','D','E','F','G','H' };

	dijkstraToEveryOtherNode(graph, 0, letters);
	cout << "\n";
	dijkstraBetweenTwoPoints(graph, 0, 7, letters);

	cout << "\n";
	dijkstraToEveryOtherNode(graph, 4, letters);
	cout << "\n";
	dijkstraBetweenTwoPoints(graph, 4, 7, letters);

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

void printDistances(int distances[], int start, int parent[], char *letters)
{
	cout << "Vertex \tDistance from Source\t\tPaths\n";
	for (int i = 0; i < 8; i++) {
		if (i != start) {
			cout << "   " << getLetter(letters, i) << " \t   " << distances[i] << "\t\t\t\t" << getLetter(letters, start) << " -> ";
			printPath(parent, i, letters);
			cout << "\n";
		}
	}
}

/***************************************************************************************

*    Usage: Used
*    Date: 03/05/2017
*    Availability: http://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
void printPath(int parent[], int j, char *letters)
{
	if (parent[j] == -1) {
		return;
	}

	printPath(parent, parent[j], letters);

	cout << getLetter(letters, j) << " -> ";
}

char getLetter(char *letters, int index) {
	return letters[index];
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
*    Date: 27/04/2017
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
void dijkstraToEveryOtherNode(int graph[8][8], int start, char *letters)
{
	cout << "*****Shortest path from " << getLetter(letters, start) << " to every other node*****\n";
	int distances[8];

	bool processed[8];
	int parent[8];

	for (int i = 0; i < 8; i++) {
		distances[i] = INT_MAX, processed[i] = false;
		parent[i] = -1;
	}

	distances[start] = 0;

	for (int i = 0; i < 8 - 1; i++)
	{
		int minDist = minDistance(distances, processed);
		processed[minDist] = true;

		for (int j = 0; j < 8; j++) {
			if (!processed[j] && graph[minDist][j] && distances[minDist] != INT_MAX
				&& distances[minDist] + graph[minDist][j] < distances[j]) {
				distances[j] = distances[minDist] + graph[minDist][j];
				parent[j] = minDist;
			}
		}
	}
	printDistances(distances, start, parent, letters);
}

/***************************************************************************************

*    Usage: Modified
*    Title: Greedy Algorithms | Set 7 (Dijkstra’s shortest path algorithm)
*    Date: 27/04/2017
*    Availability: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*
***************************************************************************************/
void dijkstraBetweenTwoPoints(int graph[8][8], int start, int end, char *letters) {
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

	cout << "Distance from " << getLetter(letters, start) << " to " << getLetter(letters ,end) << " is " << distances[end] << "\n";
}