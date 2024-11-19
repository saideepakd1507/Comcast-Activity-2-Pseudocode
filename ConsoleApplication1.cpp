#include <iostream>
using namespace std;

int divide(int array[], int firstElement, int lastElement)
{
	int pivot = array[lastElement]; //here i'm choosing pivot as last 
	int a = firstElement - 1; //since index starts from zero and less than pivot 

	for (int b = firstElement; b < lastElement; b++)
	{
		if (array[b] < pivot) // if current element is less than pivot
		{
			a++; // we are incrementing a 
			//then we have to swap elements a value to b value and making smaller element to left of the pivot

			int temp = array[a];
			array[a] = array[b];
			array[b] = temp;
		}
	}
	// now we swap pivot with the element at a+1 to the place the pivot for its exact position
	int temp = array[a + 1];
	array[a + 1] = array[lastElement];
	array[lastElement] = temp;

	return a + 1; //return the divide index
}

void sort(int array[], int lowElement, int highElement)
{
	if(lowElement < highElement)
	{
		int pivot = divide(array, lowElement, highElement);
		sort(array, lowElement, pivot - 1);
		sort(array, pivot + 1, highElement);
	}
}

double sortAndFindMedian(int array[], int num) {
	sort(array, 0, num - 1); // Sorting the element using quicksort here

	// checking whether number is even or not
	if (num % 2 == 0) {
		return (array[num / 2 - 1] + array[num  / 2]) / 2.0;
	}
	else {
		return array[num / 2];
	}
}

int main() {
	int size;
	cout << "Enter the number of elements in the array: ";
	cin >> size;

	int* array = new int[size];

	cout << "Enter " << size << " elements:\n";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	double median = sortAndFindMedian(array, size);

	cout << "Sorted Array is: ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "\nMedian value is: " << median;

	return 0;
}