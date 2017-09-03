#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Autocomplete.h"

using namespace std;

// Autocomplete constructor
Autocomplete::Autocomplete()
{
// set terms to 0
	terms = 0;
}

// insert function
void Autocomplete::insert (Term new_term)
{
// push the new terms onto the vector term
	term.push_back(new_term);
}

// Search function
void Autocomplete::Search (string key, int num)
{
	clock_t begin, end;
	begin = clock();

// make the index call the binary search to find the term
	int index = BS_helper(key, 0, term.size());

// if the index equals -1 return
	if (index == -1)
	{
		return;
	}

// else
	else
	{
		// make an up and down index
		int up = index + 1;
		int down = index - 1;

// make while loop to run up the term vector until the key is no longer found
		while (((term[up]).getQuery().substr(0, key.length())) == key)
		{
			// add each term with the key to the match vector 
			match.push_back(term[up]);
			up++;
		}
// make while loop to run down the term vector until the key is no longer found
		while (((term[down]).getQuery().substr(0, key.length())) == key)
		{
			// add each term with the key to the match vector
			match.push_back(term[down]);
			down--;
		}
	}

	end = clock();
	double elaspsed_secs = double(end - begin) / CLOCKS_PER_SEC;

// if the match vector is empty return
	if (match.size() == 0)
	{
		return;
	}

// sort the match vector by weight
	weightSort();

// if the match vector is less than the number argument
	if (match.size() < num)
	{
		cout << "Time for searching all matched terms: " << elaspsed_secs << " seconds." << endl;

		// for loop to print all the terms in the match vector
		for (int k = 0; k < match.size(); k++)
		{
			cout << match[k] << endl;
		}

// clear the vector
		match.clear();
		return;
	}

// else 
	else
	{
		cout << "Time for searching all matched terms: " << elaspsed_secs << " seconds." << endl;
		
		// for loop to print the top terms in the match vector up until the number argument
		for (int j = 0; j < num; j++)
		{
			cout << match[j] << endl;
		}
	}
	// sort the match vecotr by weight and clear it
	weightSort();
	match.clear();
}

// binary search
int Autocomplete::BS_helper(string key, int left, int right)
{
	// make middle term
	int middle = (left + right) / 2;

// if the left term is greater than the right term return -1
	if (left > right)
	{
		return -1;
	}

// else
	else
	{
		// if the middle term is greater than the key return binary search with middle - 1
		if ((term[middle]).getQuery().substr(0, key.length()) > key)
		{
			return BS_helper(key, left, middle - 1);
		}

// if middle term is less than the key return binary search with middle + 1
		else if ((term[middle]).getQuery().substr(0, key.length()) < key)
		{
			return BS_helper(key, middle + 1, right);
		}

// else return middle
		else
		{
			return middle;
		}
	}
}

// lexicographical order function using quick sort
void Autocomplete::Lexicographical(long left, long right)
{
	long i = left;
	long j = right;
	string query_temp;
	string query_pivot = term[(left + right) / 2].query;
	long weight_temp;
	long weight_pivot = term[(left + right) / 2].weight;

// while i is less than or equal to j
	while (i <= j)
	{
		// while the term query is less than the query pivot point add to i
		while (term[i].query < query_pivot)
		{
			i++;
		}

		// while the term query is greater than the query pivot point subtract from j
		while (term[j].query > query_pivot)
		{
			j--;
		}

		// if i <= j swap i and j in query and weight, add to i subtract from j
		if (i <= j)
		{
			swap (term[i].query, term[j].query);
			swap (term[i].weight, term[j].weight);
			i++;
			j--;
		}
	}
	
	// recursivley call the quick sort for each condition
	if (left < j)
	{
		Lexicographical(left, j);
	}
	if (i < right)
	{
		Lexicographical(i, right);
	}
}

// reverse weight sort 
void Autocomplete::weightSort()
{
// for loop to loop through match vector
	for (int i = 0; i < match.size() - 1; i++)
	{
		for (int k = 0; k < match.size() - 1; k++)
		{
// sort match weights
			if ((match[k]).getWeight() < (match[k + 1]).getWeight())
			{
				swap(match[k], match[k + 1]);
			}
		}
	}
}

// make a function to get vector size
int Autocomplete::getVectorSize()
{
	return term.size();
}