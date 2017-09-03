#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Term.h"
#include "Autocomplete.h"

using namespace std;

// main file with command line arguments
int main(int argc, char** argv)
{
// make a bool if the key was found in the file
	bool found_in_file = true;
// make a string called value
	string value;
// ifstream
	ifstream in_file;
// make an autocomplete object
	Autocomplete autocomplete;

// if argument number in command line != 3
	if (argc != 3)
	{
// output there needs to be three arguments
		cout << "Please enter 3 command line arguments" << endl;
		return 1;
	}

// make a result argument to integer as argument 2 in command line
	int result = atoi(argv[2]);

// open the file as argument 1 in command line
	in_file.open(argv[1]);

// if the file fails to open
	if (in_file.fail())
	{
// output the file was not found
		cout << "File not found" << endl;
		return 2;
	}

// make a string called line
	string line;

// do while loop 
	do 
	{
// while loop and getline
		while (getline(in_file, line))
		{
// long value for weight that finds the tab 
			long weight = atol(line.substr(0, line.find('\t')).c_str());
// string query that goes from the tab to the new line
			string query = line.substr(line.find('\t'), line.find('\n')).c_str();
// erase the query
			query = query.erase(query.find('\t'), query.find_first_not_of(" \t\r\n"));

// make a term object with query and weight
			Term Term(query, weight);
// call insert function with term argument
			autocomplete.insert(Term);
		}
// output to enter a value
		cout << "Please enter a search value (exit to quit): " << endl;
// get the input value as the key
		cin >> value;

// if the value is exit
		if (value == "exit")
		{
// exit the loop
			found_in_file = false;
			continue;
		}

		// make a variable to get the vector size
		int vector_size = autocomplete.getVectorSize();

		clock_t begin, end;
		begin = clock();

		// sort the term vector from position 0 to the size of the vector - 1
		autocomplete.Lexicographical(0, vector_size - 1);
		end = clock();
		double elaspsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "Time for sorting all terms: " << elaspsed_secs << " seconds." << endl;

		// call the search function 
		autocomplete.Search(value, result);
	}while(found_in_file);

// close the file 
	in_file.close();

	return 0;
}