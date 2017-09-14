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
		Autocomplete();

		void insert(Term newterm);

		void Search(string key, int num);

		int BS_helper(string key, int left, int right);

		void Lexicographical(long left, long right);

		void weightSort();

		int getVectorSize();

	private:
		int terms;
		vector<Term> term;
		vector<Term> match;
};

#endif
