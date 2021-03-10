// Name: Hamid Suha
// Lab - Dynamic Array

#include <iostream>

using namespace std;

// Array of numbers based upon user input
int main() {

	int ArrSize;

	int flag = 0;
	do
	{
		// Ask the user for how big to size the array
		cout << "Enter a number as the size of the array \n";
		cin >> ArrSize;

		// Create an array based upon the size
		int* MyArray;
		MyArray = new int[ArrSize];

		// Ask for a number, add that number to the array
		for (int i = 0; i < ArrSize; i++) {
			cout << "Entr a number to be added to the Array\n";
			cin >> MyArray[i];
		};

		for (int i = 0; i < ArrSize; i++) {
			cout << MyArray[i]<<" ";
		};
		cout << endl;
		// Enter -1 to quit
		cout << "Enter -1 to quit" << endl;
		cin >> flag;

		// Clear memory
		delete[] MyArray;

	} while (flag != -1);

	
	return 0;
}