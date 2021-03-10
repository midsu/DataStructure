// Student-  Hamid Suha
// Lab - Binary Tree

#include <iostream>
using namespace std;

class BinaryTree
{
	private:
		int count, *dataArray, size;

	public:
		BinaryTree()
		{
			dataArray = new int[10];
			size = 10;
			count = 0;
		}

		void push(int n)
		{
			if (count < size)
			{
				dataArray[count++] = n;
			}
			else
			{
				size = size * 2;
				int* temp = new int[size];
				for (int i = 0; i < count; i++)
				{
					temp[i] = dataArray[i];
				}
				delete[] dataArray;
				dataArray = temp;
				dataArray[count++] = n;
			}
		}

		void preorder(int i)
		{
			if (i < count)
			{
				cout << dataArray[i] << " ";
				preorder(2 * i + 1);
				preorder(2 * i + 2);
			}
		}
};

int main()
{
	BinaryTree btree;
	for (int i = 0; i < 20; i++)
	{
		btree.push(i);
	}
	btree.preorder(0);
	cout << endl;

	return 0;
	system("pause");
}