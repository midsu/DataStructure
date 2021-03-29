#include <string>       
#include <iostream>     
#include <sstream>   
using namespace std;


int main() {
	string sentence;
	string word;
	int number;

	// Read a sentence
	cout << "Enter a sentence: \n";
	getline(cin, sentence);

	// Turn sentence to sstream
	stringstream stream;
	stream.str(sentence);

	// Check sentence, if there's a number, double it
	while (stream >> word)
	{
		if (stringstream(word)>> number) 
		{
			cout << "- " << number * number << endl;
		}
		else 
		{
			cout << "- " << word << endl;
		}
		
	}

	system("pause");
	return 0;
}

/* 

OUTPUT:

Enter a sentence:
There exists 7 dimensions
- There
- exists
- 49
- dimensions
Press any key to continue . . .



*/