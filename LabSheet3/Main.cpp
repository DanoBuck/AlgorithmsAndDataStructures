#include <iostream>
using namespace std;

void mergeSort(int*, int, int);
void merge(int *, int, int, int);

void quickSort(int*, int, int);
int quickSortDivide(int*, int, int);
void swapper(int&, int&);

void print(int*, int);

int main() {
	cout << "*************************Quicksort Algorithm*************************\n";
	int array1[7] = { 38,27,43,3,9,82,10 };
	quickSort(array1, 0, 6);
	print(array1, 7);

	int array2[33] = { 84 ,19 ,10 ,7 ,9 ,16 ,20 ,13 ,4 ,23 ,74 ,6 ,29 ,86 ,61 ,26 ,17 ,65 ,64 ,78 ,63 ,92 ,37 ,85 ,80 ,90 ,35 ,82 ,96 ,89 ,83 ,77 ,33 };
	quickSort(array2, 0, 32);
	print(array2, 33);

	cout << "\n*************************Mergesort Algorithm*************************\n";
	int array3[6] = { 5,4,3,21,16 };
	mergeSort(array3, 0, 4);
	print(array3, 5);

	int array4[34] = { 84 ,19 ,10 ,7 ,9 ,16 ,20 ,13 ,4 ,23 ,74 ,6 ,29 ,86 ,61 , 50012, 26 ,17 ,65 ,64 ,78 ,63 ,92 ,37 ,85 ,80 ,90 ,35 ,82 ,96 ,89 ,83 ,77 ,33 };
	mergeSort(array4, 0, 33);
	print(array4, 34);

	system("pause");
	return 0;
}

/***************************************************************************************

*    Usage: based
*    Date: 6/2/2017
*    Availability: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm
*
***************************************************************************************/
void mergeSort(int *arrayIn, int startIndex, int lastIndex) {
	int midpoint = 0;

	if (startIndex < lastIndex) {
		midpoint = (startIndex + lastIndex) / 2;
		mergeSort(arrayIn, startIndex, midpoint);
		mergeSort(arrayIn, midpoint + 1, lastIndex);
		merge(arrayIn, startIndex, midpoint, lastIndex);
	}
	else {
		return;
	}
}

/***************************************************************************************

*    Usage: based
*    Date: 6/2/2017
*    Availability: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm
*
***************************************************************************************/
void merge(int *myArray1, int low, int middle, int high) {
	int l1, l2, i;
	int *newArray;

	newArray = new int[100];

	for (l1 = low, l2 = middle + 1, i = low; l1 <= middle && l2 <= high; i++) {
		if (myArray1[l1] <= myArray1[l2]) {
			newArray[i] = myArray1[l1++];
		}
		else {
			newArray[i] = myArray1[l2++];
		}
	}

	while (l1 <= middle) {
		newArray[i++] = myArray1[l1++];
	}

	while (l2 <= high) {
		newArray[i++] = myArray1[l2++];
	}
	for (i = low; i <= high; i++) {
		myArray1[i] = newArray[i];
	}
}

void swapper(int &num1, int &num2) {
	int holder = num1;
	num1 = num2;
	num2 = holder;
}


/***************************************************************************************

*    Usage: based
*    Date: 7/2/2017
*    Availability: https://en.wikipedia.org/wiki/Quicksort
*
***************************************************************************************/
void quickSort(int *arrayIn, int left, int right) {
	if (left < right) {
		int partitions = quickSortDivide(arrayIn, left, right);
		quickSort(arrayIn, left, right - 1);
		quickSort(arrayIn, partitions + 1, right);
	}
}

/***************************************************************************************

*    Usage: based
*    Date: 6/2/2017
*    Availability: http://www.algolist.net/Algorithms/Sorting/Quicksort
*
***************************************************************************************/
int quickSortDivide(int *arrayIn, int left, int right) {
	int i = left, j = right;

	int pivot = arrayIn[(left + right) / 2];

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
		quickSortDivide(arrayIn, left, j);
	}
	if (i < right) {
		quickSortDivide(arrayIn, i, right);
	}
	return i;
}

void print(int *myArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << myArray[i] << " ";
	}
	cout << "\n";
}