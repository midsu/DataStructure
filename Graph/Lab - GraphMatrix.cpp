// Student - Hamid Suha
// Lab - Graph Matrix

#include <iostream>
using namespace std;


int main()
{
    int numOfVertices;
    // User define number of Vertices
    cout << "How many vertices? ";
    cin >> numOfVertices;

    // Creating dynamic Arrays of Labels and adjacency
    char* labels = new char [numOfVertices];
    int** adjacency = new int* [numOfVertices];
    for (int i = 0; i < numOfVertices; i++) 
    {
        adjacency[i] = new int[numOfVertices];
    }

    // User input labels to vertices
    for (int i = 0; i < numOfVertices; i++)
    {
        cout << "What is the label for vertex " << i + 1 << "? ";
        cin >> labels[i];
    }

    // User defining edge for vertices
    cout << "Define an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop." << endl;
    while (true)
    {
        string temp1, temp2;
        cin >> temp1;
        if (temp1.compare("-1") == 0)
            break;
        cin >> temp2;
        int i, j;
        for (i = 0; i < numOfVertices; i++)
            if (temp1[0] == labels[i])
                break;
        for (j = 0; j < numOfVertices; j++)
            if (temp2[0] == labels[j])
                break;
        adjacency[i][j] = 1;
        cout << "Added Edge " << temp1[0] << "->" << temp2[0] << endl;
    }

    // Outputing 
    cout << "Your edges are: ";
    for (int i = 0; i < numOfVertices; i++)
        for (int j = 0; j < numOfVertices; j++)
            if (adjacency[i][j] == 1)
                cout << labels[i] << labels[j] << " ";
    cout << endl;

    return 0;
    system("pause");
}

/*
How many vertices? 6
What is the label for vertex 1? A
What is the label for vertex 2? B
What is the label for vertex 3? C
What is the label for vertex 4? D
What is the label for vertex 5? E
What is the label for vertex 6? F
Define an edge by listing a pair of vertices, i.e. "A B", or -1 to stop.
A B
Added Edge A->B
B A
Added Edge B->A
-1
Your edges are: AB BA
*/
