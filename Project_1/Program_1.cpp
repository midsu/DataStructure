// Student - Hamid Suha
// Program - 1

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

// Linked List Structure
struct node {
	float data;
	struct node *next;
};


// Linked List Class 
class stack {
	struct node* top;
public:
	stack()
	{
		top = NULL;
	}
    // Constructors
	void push(float element);   // Pushing an Element
	float pop();                // Poppng an element
	float peek();               // Top Of Stack
	bool isEmpty();             // Checking If List Is Empty
	int size();                 // Checking Size
};

// Check Stack Emptiness
bool stack::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}

float stack::peek()
{
	if (top == NULL)
	{
		cout << "Error: Empty Stack ";
	}
	return top->data;
}

// Push Input Into Stack
void stack::push(float element)
{
	struct node* newNode;
	newNode = new node;
	newNode->data = element;
	newNode->next = NULL;
	if (top != NULL)
	{
		newNode->next = top;
	}
	top = newNode;
}

// Pop Top Element From Stack
float stack::pop()
{
	struct node *temp;
	if (top == NULL)
	{
		cout << "Error: Empty Stack ";
	}
	temp = top;
	top = top->next;
	float value = temp->data;
	delete temp;
	return value;
}

// Check Size Of Stack
int stack::size()
{
	struct node *temp;
	temp = top;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}


// Main Function
int main()
{
	cout << "Enter your expresion followed by space: " << endl;
	
    while (1) {
        stack s;
        float first, second;
        string input, str1;

        getline(cin, input);
        istringstream is(input); //Use To Parsing Input

        //If User Input Is 0
        if (input == "0") 
        {
            return 0;
        }
        //Default For Flag
        bool flag = true;

        //Loop Until User Input An Expression
        for (; is >> str1;) {

            if (str1.compare("+") == 0) 
            {
                if (s.size() < 2) {
                    cout << "Error: Too many operators\n";
                    flag = false;
                    break;
                }
                /*
                pop two elements from the stack,
                apply operator(here +) and push the result into
                the stack
                */
                second = s.pop();
                first = s.pop();
                s.push(first + second);     //Push Result In Stack
            }
            else if (str1.compare("-") == 0) 
            {
                
                // Check If There Is More Than One Operator
                if (s.size() < 2) 
                {
                    cout << "Error: Too many operators\n";
                    flag = false;
                    break;
                }
                /*
                pop two elements from the stack,
                apply operator(here -) and push the result into
                the stack
                */
                second = s.pop();
                first = s.pop();
                s.push(first - second);     //Push Result In Stack
            }
            else if (str1.compare("*") == 0) 
            {
                if (s.size() < 2) 
                {
                    cout << "Error: Too many operators\n";
                    flag = false;
                    break;
                }
                second = s.pop();
                first = s.pop();
                s.push(first * second);     //Push Result In Stack
            }
            else if (str1.compare("/") == 0) 
            {
                if (s.size() < 2) 
                {
                    cout << "Error: Too many operators\n";
                    flag = false;
                    break;
                }
                /*
                pop two elements from the stack,
                apply operator(here /) and push the result into
                the stack and if the second is 0 get the errors
                */
                second = s.pop();
                first = s.pop();
                if (second == 0) 
                {
                    cout << "Error: Division by zero\n";
                    flag = false;
                    break;
                }
                s.push(first / second);     //Push Result In Stack
            }
            else 
            {
                s.push(strtof(str1.c_str(), NULL));
            }
        }

        /*
        check if the size of stack
        and flag is tru else there is more than two operand for each operator
        */
        if (s.size() == 1 && flag)
        {
            cout << "= " << s.pop();
            cout << "\n";
        }
        else if (s.size() > 1)
        {
            cout << "Error: Too many operands \n";
        }
    }
    system("pause");
    return 0;
}


/*
  OUTPUT:
    Enter your expresion followed by space:
    10 15 +
    = 25
    10 15 -
    = -5
    2.5 3.5 +
    = 6
    10 0 /
    Error: Division by zero
    10 20 *
    = 200
    -10 -20 -
    = 10
    100 10 50 25 / * - -2 /
    = -40

*/
