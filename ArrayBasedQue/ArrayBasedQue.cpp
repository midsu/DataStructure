// Name- Hamid Suha
// Lab - Array Based Queue

#include<iostream>
using namespace std;


#define SIZE 10

class Queue
{
private:
	int MyArray[SIZE];
	int count;
	int front, back;

public:
	Queue()
	{
		front = -1;
		back = -1;
		count = 0;
	}

	bool isEmpty()
	{
		if (front == -1 && back == -1)
			return true;
		else
			return false;
	}

	bool IsFull()
	{
		return (back + 1) % SIZE == front ? true : false;
	}

	void Enqueue(int value)
	{
		if (back == SIZE - 1)
			cout << "Ques is full \n";
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			count++;
			back++;
			MyArray[back] = value;
		}
	}

	void Dequeue()
	{
		if (isEmpty())
			cout << "Queue is empty \n" << endl;
		else
		{
			if (front == back)
			{
				front = back = -1;
			}
			else
				front++;
			count--;
		}

	}

	void showfront()
	{
		if (isEmpty())
			cout << "Queue is empty \n" << endl;
		else
			cout << "Element at front is: " << MyArray[front] <<"\n "<< endl;
	}

	void display()
	{
		if (isEmpty())
			cout << "Queue is empty \n" << endl;
		else
		{
			for (int i = front; i <= back; i++)
				cout << MyArray[i] << " ";
		}
		cout << "\n"<< "Count: "<< count << endl;
	}
};

int main()
{
	Queue Q;
	Q.Enqueue(2);
	Q.Enqueue(4);
	Q.Enqueue(6);

	Q.display();
	cout << endl;

	Q.Dequeue();

	Q.display();
	cout << endl;

	Q.showfront();

	system("pause");
	return 0;
}

/*
	OUTPUT:
	2 4 6
	4 6
	Element at front is: 4
	Press any key to continue . . .

*/