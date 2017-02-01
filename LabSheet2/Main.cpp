#include <iostream>
using namespace std;

template <typename T> 
void swapper(T &t1, T &t2);
template <typename T> 
void swapper2(T *t1, T *t2);

template <typename T> 
void multiples(T &sum, T x, int n);

template <typename T1, typename T2>
T1 init(T1 num1, T1 num2, T2& start);

template <typename T>
int partition(T *arrayToSort, int left, int right);

template<typename T>
T* quicksort(T* arrayToSort, int size);

template<typename T>
void printArray(T &arrayToPrint, int numberOfElements);

int main() {
	int t1 = 5, t2 = 10;
	swapper(t1, t2);
	
	cout << "Working with ints\n";
	cout << "Pass By Reference\n";
	cout << "t1 = " << t1 << " which should be 10\n";
	cout << "t2 = " << t2 << " which should be 5\n";

	swapper2(&t1, &t2);
	cout << "\nPass By Address\n";
	cout << "t1 = " << t1 << " which should be 5\n";
	cout << "t2 = " << t2 << " which should be 10\n";

	float t3 = 15, t4 = 20;
	swapper(t3, t4);

	cout << "\nWorking with floats\n";
	cout << "Pass By Reference\n";
	cout << "t3 = " << t3 << " which should be 20\n";
	cout << "t4 = " << t4 << " which should be 15\n";

	swapper2(&t3, &t4);
	cout << "\nPass By Address\n";
	cout << "t3 = " << t3 << " which should be 15\n";
	cout << "t4 = " << t4 << " which should be 20\n";

	int sum = 0;
	int x = 1;
	int n = 3;

	multiples(sum, x, n);

	cout << "\nThe sum is: " << sum << "\n";

	x = 2;
	sum = 0;
	multiples(sum, x, n);

	cout << "\nThe sum is: " << sum << "\n";

	double start = 2.2;
	cout << "\nInit = " << init(2, 3, start) << "\n";
	cout << "Start has been set to: " << start << "\n\n";

	cout << "Starting to sort arrays now" << "\n\n";

	// Testing quicksort method with Integers
	int myIntArray[7] = { 5, 4, 100, 20, 3, 2, 1 };
	int *myIntArray2 = quicksort(myIntArray, 6);
	printArray(myIntArray2, 7);

	// Testing quicksort method with Floats
	float myFloatsArray[10] = { 1700, 2600, 100, 109, 45000, 21, 2045, 709, 12222, 5 };
	quicksort(myFloatsArray, 9);
	printArray(myFloatsArray, 10);

	// Testing quicksort method with Doubles
	double myDoubleArray[17] = { 113690, 124121, 131020, 59855, 71473, 50580, 46526	, 124939, 31185, 
		129475, 100353, 122875, 88236,	43552, 79356, 115913, 10 };
	quicksort(myDoubleArray, 16);
	printArray(myDoubleArray, 17);

	cout << "\n";
	system("pause");
	return(0);
}

// Question 1 Pass By Reference
template <typename T> void swapper(T &t1, T &t2)
{
	T holder = t2;
	t2 = t1;
	t1 = holder;
}

// Question 1 Pass By Address which 
template <typename T> void swapper2(T *t1, T *t2) {
	T holder = *t2;
	*t2 = *t1;
	*t1 = holder;
}

// Question 2
template <typename T> void multiples(T &sum, T x, int n) {
	// As the example shows "sum = 1 + x + 2x + 3x + ... + nx"
	// I start the multiple x by (i+1) i.e 1,2,3,4,5,6,7,8,...
	for (int i = 0; i < n; i++) {
		sum += (i+1) * x;
	}
	sum += 1;
}

// Question 3 
template <typename T1, typename T2> T1 init(T1 num1, T1 num2, T2 &start) {
	// init sets the value of the parameter start to a T2 - type value of 1
	T1 typeToSetStart = 1;
	start = typeToSetStart;

	T1 returnValue = num1 + num2;

	// init returns a T1 - type value which is the sum of num1 and num2.
	return returnValue;
}

/*
* Based on code found at http://www.geeksforgeeks.org/iterative-quick-sort/
* on the 1/2/2017
*/
template <typename T> int partition(T *arrayToSort, int left, int right)
{
	T x = *arrayToSort;
	x = arrayToSort[right];
	int i = (left - 1);

	for (int j = left; j < right; j++)
	{
		if (arrayToSort[j] <= x)
		{
			i++;
			swapper2(&arrayToSort[i], &arrayToSort[j]);
		}
	}
	swapper2(&arrayToSort[i + 1], &arrayToSort[right]);
	return (i + 1);
}


/*
* Question 4
* Based on code found at http://www.geeksforgeeks.org/iterative-quick-sort/
* on the 1/2/2017
*/
template<typename T> T* quicksort(T* arrayToSort, int size) {
	
	T arrayToHelpMeSort[20];
	int top = 0;
	int left = 0;
	int right = size;
	arrayToHelpMeSort[top] = left;
	arrayToHelpMeSort[++top] = right;

	while (top >= 0) {
		right = arrayToHelpMeSort[top--];
		left = arrayToHelpMeSort[top--];


		int pivot = partition(arrayToSort, left, right);

		if (pivot - 1 > left)
		{
			arrayToHelpMeSort[++top] = left;
			arrayToHelpMeSort[++top] = pivot - 1;
		}

		if (pivot + 1 < right)
		{
			arrayToHelpMeSort[++top] = pivot + 1;
			arrayToHelpMeSort[++top] = right;
		}
	}
	return arrayToSort;
}

// Function to print elements in array
template<typename T>
void printArray(T &arrayToPrint, int numberOfElements) {
	for (int i = 0; i < numberOfElements; i++) {
		cout << arrayToPrint[i] << " ";
	}
	cout << "\n";
}
