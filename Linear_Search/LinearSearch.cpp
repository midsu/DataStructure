/*
Student- Hamid Suha
Lab - Linear Search

*/

#include <iostream>
using namespace std;


int main()
{
	const int size = 10;
	int Array[size];

	// Create an array
	for (int i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "] Element " << "to add to Array: ";
		cin >> Array[i];
	} cout << endl;

	// Ask for a key to search
	int value;
	cout << "Enter a number to search from the list: ";
	cin >> value;
	cout << endl;

	// Print the key placement, otherwise -1
	for (int i = 0; i < size; i++)
	{
		if (value == Array[i])
		{
			cout << "Value found at index -{" << i << "}-" << endl;
			return 0;
		}
	}
	cout << "-1 \n";


	system("pause");
	return 0;
}


/*
	OUTPUT:
	Enter [0] Element to add to Array: 2
	Enter [1] Element to add to Array: 4
	Enter [2] Element to add to Array: 6
	Enter [3] Element to add to Array: 8
	Enter [4] Element to add to Array: 1
	Enter [5] Element to add to Array: 3
	Enter [6] Element to add to Array: 5
	Enter [7] Element to add to Array: 7
	Enter [8] Element to add to Array: 10
	Enter [9] Element to add to Array: 8

	Enter a number to search from the list: 4

	Value found at index -{1}-
*/