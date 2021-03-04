// Student - Hamid Suha
// Project - Program 2


#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Declare the class Node
class Node
{
public:
    //Declare the variables
    std::string name;
    int weight;
    Node* next;
    Node* prev;
    Node* wNext;
    Node* wPrev;

    Node(std::string newName, int newWeight)
    {
        name = newName;
        weight = newWeight;
    }
}*head, * weightHead;

// Declare the class doubly linked list
class DLL
{
public:
    void makeList(std::string n, int w);
    void insertion(std::string n, int w);
    void insertStart(std::string n, int w);
    void insertAfter(std::string n, int w);
    void checkWeight(Node*);
    void printNames();
    void printWeights();
    DLL()
    {
        head = NULL;
    }
};
//create the list
void DLL::makeList(std::string n, int w)
{
    Node* h, *temp, *wH;
    temp = new Node(n, w);
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        weightHead = temp;
    }
    else
    {
        h = head;
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = temp;
        temp->prev = h;
    }
}
//declare the insertion data function
void DLL::insertion(std::string n, int w)
{
    Node* temp, * h, * wH;
    h = head;
    wH = weightHead;
    temp = new Node(n, w);
    if (temp->name < h->name)
    {
        insertStart(n, w);
        return;
    }
    else
    {
        if (h->next == NULL)
        {
            insertAfter(n, w);
            return;
        }
        while (h->next != NULL)
        {
            h = h->next;
            if (h->next == NULL || temp->name > h->next->name)
            {
                insertAfter(n, w);
                return;
            }
        }
    }
}

void DLL::insertStart(std::string n, int w)
{
    Node* temp = new Node(n, w);
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    checkWeight(temp);
}

void DLL::insertAfter(std::string n, int w)
{
    Node* temp, * h, * wH;
    h = head;
    wH = weightHead;
    temp = new Node(n, w);
    //Add to next place in list
    if (h->next == NULL)
    {
        h->next = temp;
        temp->next = NULL;
        temp->prev = h;
        checkWeight(temp);
    }
    else
    {
        while (h->next != NULL)
        {
            h = h->next;
            //If current head is higher up, place temp here and move *head node down
            if (temp->name < h->name)
            {
                temp->next = h;
                temp->prev = h->prev;
                temp->next->prev = temp;
                temp->prev->next = temp;
                checkWeight(temp);
                return;
            }
            //Otherwise just enter it on the end
            else if (h->next == NULL)
            {
                h->next = temp;
                temp->prev = h;
                checkWeight(temp);
                return;
            }
        }

    }
}

void DLL::checkWeight(Node* temp)
{
    Node* wH = weightHead;
    //Heavier Weight
    if (wH->weight < temp->weight)
    {
        while (wH->wNext != NULL && wH->weight < temp->weight)
        {
            wH = wH->wNext;
        }
        if (wH->weight > temp->weight)
        {
            temp->wNext = wH;
            temp->wPrev = wH->wPrev;
            temp->wPrev->wNext = temp;
            temp->wNext->wPrev = temp->wPrev;
        }
        else
        {
            temp->wNext = NULL;
            temp->wPrev = wH;
            temp->wPrev->wNext = temp;
            return;
        }
        wH = temp;
    }
    //Lighter Weight
    else
    {
        temp->wNext = wH;
        temp->wPrev = NULL;
        temp->wNext->wPrev = temp;
        weightHead = temp;
    }
    return;
}

void DLL::printNames()
{
    Node* temp = head;
    std::cout << "\nNames & weights sorted(ascending) by name:\n";
    while (temp != NULL)
    {
        std::cout << temp->name << " - " << temp->weight << std::endl;
        temp = temp->next;
    }
}
void DLL::printWeights()
{
    Node* temp = weightHead;
    std::cout << "\nNames & weights sorted(ascending) by weight:\n";
    while (temp != NULL)
    {
        std::cout << temp->name << " - " << temp->weight << std::endl;
        temp = temp->wNext;
    }
}

int main()
{
    DLL* roster = new DLL();
    std::string name;
    int weight;

    std::cout << "Enter first name: ";
    std::cin >> name;
    std::cout << "And first weight: ";
    std::cin >> weight;
    std::cout << std::endl;
    roster->makeList(name, weight);

    for (int i = 0; i < 14; i++)
    {
        std::cout << "Enter next name: ";
        std::cin >> name;
        std::cout << "And next weight: ";
        std::cin >> weight;
        std::cout << std::endl;
        roster->insertion(name, weight);
    }

    roster->printNames();
    roster->printWeights();

}

/*

Sample Test Data:
Mark - 150
Tina - 115
Zach - 55
Amy - 140
Steve - 220
Brian - 250
Liz - 125
Brian - 220
Laura - 115
Alex - 175
Jason - 210
Eric - 175
Aaron - 195
Kim - 135
Brandon - 78


Names & weights sorted(ascending) by name:
Aaron - 195
Alex - 175
Amy - 140
Brandon - 78
Brian - 250
Brian - 220
Eric - 175
Jason - 210
Kim - 135
Laura - 115
Liz - 125
Mark - 150
Steve - 220
Tina - 115
Zach - 55

Names & weights sorted(ascending) by weight:
Zach - 55
Brandon - 78
Tina - 115
Laura - 115
Kim - 135
Alex - 175
Eric - 175
Aaron - 195

Process returned 0 (0x0)   execution time : 202.852 s
Press ENTER to continue.

*/
