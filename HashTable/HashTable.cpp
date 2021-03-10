// Studwnt - Hamid Suha
// Lab - Hash table


#include <iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
const int TABLE_SIZE = 27;

class HashTable
{
public:
	int table[TABLE_SIZE]; //Array for holding the hash table entries

	HashTable()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			//Initializing all entries with -1 to mark the table is empty.
			// Here -1 means that location in table is empty, so an item can be inserted.
			table[i] = -1;
	}

	//Takes the item and returns its hash value.
	int hash(int a)
	{
		return a % TABLE_SIZE;
	}

	//Takes the item and inserts in hash table
	void add(int a)
	{
		int hsh = hash(a);//get the hash of the item.
		int count = 0;
		//probe the table linearly untill we get an empty location or all the locations have been probed.
		while (table[hsh] != -1 && count < TABLE_SIZE)
		{
			hsh = (hsh + 1) % TABLE_SIZE;
			count = count + 1;
		}

		if (table[hsh] == -1)
		{
			//found empty location, inserting item.
			table[hsh] = a;
			cout << "Successfully added the key to hash table.";
		}
		else
			cout << "The hash table is full, no more insertions can be done.";
	}

	//Takes an item and returns same item if it is present in table else returns -1
	int lookup(int a)
	{
		int hsh = hash(a);//get the hash of the item.
		int count = 0;
		//probe the table linearly untill we get the item we are looking for
		//or an empty location or all the locations have been probed.
		while (table[hsh] != a && table[hsh] != -1 && count < TABLE_SIZE)
		{
			hsh = (hsh + 1) % TABLE_SIZE;
			count = count + 1;
		}

		if (table[hsh] == a)
		{
			//Found the key in the table
			cout << "The key is found in the table";
			return a;
		}
		else
		{
			cout << "The key is not found in the table.";
			return -1;
		}


	}
};

int main()
{
	HashTable hash;
	int key, choice;
	while (1)
	{
		cout << "\n----------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "\n----------------------" << endl;
		cout << "1.Add item into the table" << endl;
		cout << "2.Lookup item in the table" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> key;
			hash.add(key);
			break;
		case 2:
			cout << "Enter element to be looked up: ";
			cin >> key;
			hash.lookup(key);
			break;
		case 3:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}

	}
	return 0;
}
