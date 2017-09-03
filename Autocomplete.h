#include <iostream>
#include <string>
#include <vector>
#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Term.h"

using namespace std;

// Autocomplete class
class Autocomplete
{
	public:
// autocomplete constructors
		Autocomplete();
// insert finction
		void insert(Term newterm);
// search function
		void Search(string key, int num);
// BS helper
		int BS_helper(string key, int left, int right);
// binary search function
		/*void print*/
// lexicographical order function
		void Lexicographical(long left, long right);
// sort weight function
		void weightSort();
// get the size of the vector
		int getVectorSize();

	private:
		int terms;
		vector<Term> term;
		vector<Term> match;
};

#endif
