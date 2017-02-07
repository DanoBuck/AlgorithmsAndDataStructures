#include <iostream>
#include <string>
using namespace std;

template<typename T>
void print(T, int);

template<typename T>
void swapper(T&, T&);

template<typename T>
void quickSort(T*, int, int);

int main() {
	int arrayIn[10] = { 55,49,12,366,31,1,6,1200, 100, 7 };
	quickSort(arrayIn, 0, 9);
	print(arrayIn, 10);

	double arrayD[10] = { 55.678,49.121,12.21,.5,31.33,1.9,.6,.1200, 1.00, 7 };
	quickSort(arrayD, 0, 9);
	print(arrayD, 10);

	string arrayS[10] = { "Hello", "My", "Name", "Is", "Daniel", "And", "I", "Live", "In", "Tallaght" };
	quickSort(arrayS, 0, 9);
	print(arrayS, 10);
	system("pause");
	return 0;
}

template<typename T> void print(T arrayIn, int size) {
	for (int i = 0; i < size; i++) {
		cout << arrayIn[i] << " ";
	}
	cout << "\n";
}

template<typename T> void swapper(T &element1, T &element2) {
	T holder = element1;
	element1 = element2;
	element2 = holder;
}

template<typename T> void quickSort(T *arrayIn, int left, int right) {
	int i = left, j = right;

	T pivot = arrayIn[(left + right) / 2];

	while (i <= j) {
		while (arrayIn[i] < pivot) {
			i++;
		}
		while (arrayIn[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swapper(arrayIn[i], arrayIn[j]);
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort(arrayIn, left, j);
	}
	if (i < right) {
		quickSort(arrayIn, i, right);
	}
}