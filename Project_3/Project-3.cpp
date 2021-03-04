// Student - Hamid Suha
// Project - 3

#include <iostream>
#include <algorithm> // include min() and max() from algo
#include <string>
using namespace std;

// Record/Data struct
struct Record
{
	string name;
	double weight;
};
// Node struct
struct Node
{
	Record record;
	Node* left;
	Node* right;

	Node(Record record)
	{
		this->record = record;
		this->left = NULL;
		this->right = NULL;
	}
};
// BinarySearchTree class declaration
class BinarySearchTree
{
	public:
		BinarySearchTree();
		void buildTree();
		void addRecord(Record record);
		void printPreorder();
		void printInorder();
		void printPostorder();
		int getHeight();
		int getNumberOfLeaves();
		double searchName(string name);
		double getLowestWeight();
		string getFirstNameInOrder();
	private:
		Node* root;
		void addHelper(Node* node, Record record);
		void preorderHelper(Node* node);
		void inorderHelper(Node* node);
		void postorderHelper(Node* node);
		int heightHelper(Node* node);
		int numberOfLeavesHelper(Node* node);
		double searchHelper(Node* node, string name);
		double lowestWeightHelper(Node* node, double weight);
		string firstNameInOrderHelper(Node* node);
};
// BinarySearchTree class implementation
// default constructor
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}
// buildTree function implementation
void BinarySearchTree::buildTree()
{
	string name;
	double weight;
	for (int i = 0; i < 15; i++)
	{
		cout << "Enter first name: ";
		cin >> name;

		cout << "Enter associated weight: ";
		cin >> weight;
		Record record;
		record.name = name;
		record.weight = weight;
		addRecord(record);

	}
}
// addRecord function implementation
void BinarySearchTree::addRecord(Record record)
{
	if (root == NULL)
	{
		root = new Node(record);
	}
	else
	{
		addHelper(root, record);
	}
}
// printPreorder function implementation
void BinarySearchTree::BinarySearchTree::printPreorder()
{
	cout << "\nPreorder traversal:" << endl;
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		preorderHelper(root);
}
// printInorder function implementation
void BinarySearchTree::printInorder()
{
	cout << "\nInorder traversal:" << endl;
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		inorderHelper(root);
}
// printPostorder function implementation
void BinarySearchTree::printPostorder()
{
	cout << "\nPostorder traversal:" << endl;
	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		postorderHelper(root);
}
// getHeight function implementation
int BinarySearchTree::getHeight()
{
	return heightHelper(root);
}
// getNumberOfLeaves function implementation
int BinarySearchTree::getNumberOfLeaves()
{
	return numberOfLeavesHelper(root);
}
// searchName function implementation
double BinarySearchTree::searchName(string name)
{
	return searchHelper(root, name);
}
// getLowestWeight function implementation
double BinarySearchTree::getLowestWeight()
{
	if (root == NULL)
		return 0;
	else
		return lowestWeightHelper(root, root->record.weight);
}
// getFirstNameInOrder function implementation
string BinarySearchTree::getFirstNameInOrder()
{
	if (root == NULL)
		return "Tree is empty!";
	else
		return firstNameInOrderHelper(root);
}
// addHelper function implementation
void BinarySearchTree::addHelper(Node* node, Record record)
{
	if ((node->record.name).compare(record.name) > 0)
	{
		if (node->left == NULL)
		{
			node->left = new Node(record);
		}
		else
		{
			addHelper(node->left, record);
		}
	}
	else if ((node->record.name).compare(record.name) < 0)
	{
		if (node->right == NULL)
		{
			node->right = new Node(record);
		}
		else
		{
			addHelper(node->right, record);
		}
	}
	else
	{
		// should not add duplicate names
	}
}
// preorderHelper function implementation
void BinarySearchTree::preorderHelper(Node* node)
{
	if (node != NULL)
	{
		cout << node->record.name << " (" << node->record.weight << ")" << endl;
		preorderHelper(node->left);
		preorderHelper(node->right);
	}
}
// inorderHelper function implementation
void BinarySearchTree::inorderHelper(Node* node)
{
	if (node != NULL)
	{
		inorderHelper(node->left);
		cout << node->record.name << " (" << node->record.weight << ")" << endl;
		inorderHelper(node->right);
	}
}
// postorderHelper function implementation
void BinarySearchTree::postorderHelper(Node* node)
{
	if (node != NULL)
	{
		postorderHelper(node->left);
		postorderHelper(node->right);
		cout << node->record.name << " (" << node->record.weight << ")" << endl;
	}
}
// heightHelper function implementation
int BinarySearchTree::heightHelper(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + max(heightHelper(node->left), heightHelper(node->right));
	}
}
// numberOfLeavesHelper function implementation
int BinarySearchTree::numberOfLeavesHelper(Node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return numberOfLeavesHelper(node->left) + numberOfLeavesHelper(node->right);
}
// searchHelper function implementation
double BinarySearchTree::searchHelper(Node* node, string name)
{
	if (node == NULL) // not existed
		return 0.0;
	else if ((node->record.name).compare(name) > 0)
		return searchHelper(node->left, name);
	else if ((node->record.name).compare(name) < 0)
		return searchHelper(node->right, name);
	else
		return node->record.weight; // existed
}
// lowestWeightHelper function implementation
double BinarySearchTree::lowestWeightHelper(Node* node, double weight)
{
	if (node == NULL)
	{
		return weight;
	}
	else
	{
		return min(min(node->record.weight, lowestWeightHelper(node->left, node->record.weight)), min(node->record.weight, lowestWeightHelper(node->right, node->record.weight)));
	}
}
// firstNameInOrderHelper function implementation
string BinarySearchTree::firstNameInOrderHelper(Node* node)
{
	if (node->left == NULL)
		return node->record.name;
	else
		return firstNameInOrderHelper(node->left);
}

// start main function
int main()
{
	BinarySearchTree tree;
	tree.buildTree();
	tree.printPreorder();
	tree.printInorder();
	tree.printPostorder();
	cout << "\nHeight of the tree: " << tree.getHeight() << endl;
	cout << "\nNumber of leaves in the tree: " << tree.getNumberOfLeaves() << endl;
	cout << "\nFirst name in the tree in alphabetical order: " << tree.getFirstNameInOrder() << endl;
	cout << "\nLowest weight contained in the tree: " << tree.getLowestWeight() << endl;

	string name;
	cout << "\nenter the key: ";
	cin >> name;

	double weight = tree.searchName(name);
	if (weight == 0.0)
		cout << name << "\n is not existed in the tree." << endl;
	else
		cout <<  name << "\n is existed in the tree and his/her weight is: " << weight << endl;


	return 0;
}




/*
Enter first name: Mike
Enter associated weight: 220
Enter first name: Brianna
Enter associated weight: 120
Enter first name: Karl
Enter associated weight: 109
Enter first name: Stephanie
Enter associated weight: 130
Enter first name: Roger
Enter associated weight: 199
Enter first name: Zelda
Enter associated weight: 145
Enter first name: Chuck
Enter associated weight: 145
Enter first name: Iris
Enter associated weight: 240
Enter first name: Alen
Enter associated weight: 180
Enter first name: Mike
Enter associated weight: 135
Enter first name: Rose
Enter associated weight: 95
Enter first name: Joe
Enter associated weight: 155
Enter first name: Lily
Enter associated weight: 100
Enter first name: Bob
Enter associated weight: 172
Enter first name: Ali
Enter associated weight: 200

Preorder traversal:
Mike (220)
Brianna (120)
Alen (180)
Bob (172)
Ali (200)
Karl (109)
Chuck (145)
Iris (240)
Joe (155)
Lily (100)
Stephanie (130)
Roger (199)
Rose (95)
Zelda (145)

Inorder traversal:
Alen (180)
Ali (200)
Bob (172)
Brianna (120)
Chuck (145)
Iris (240)
Joe (155)
Karl (109)
Lily (100)
Mike (220)
Roger (199)
Rose (95)
Stephanie (130)
Zelda (145)

Postorder traversal:
Ali (200)
Bob (172)
Alen (180)
Joe (155)
Iris (240)
Chuck (145)
Lily (100)
Karl (109)
Brianna (120)
Rose (95)
Roger (199)
Zelda (145)
Stephanie (130)
Mike (220)

Height of the tree: 6

Number of leaves in the tree: 5

First name in the tree in alphabetical order: Alen

Lowest weight contained in the tree: 95

enter the key: Rose

Rose is existed in the tree and his/her weight is: 95

*/