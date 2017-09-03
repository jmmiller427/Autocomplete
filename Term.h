#include <iostream>
#include <string>
#include <vector>
#ifndef TERM_H
#define TERM_H

using namespace std;

// make term class
class Term
{
	public:
// term constructors
		Term();
		Term(string query, long weight);
// reverse weight order
		int byReverseWeightOrder(Term term1, Term term2);
// compare function
		int compareTo(Term term1, Term term2);
// prefix order function
		int byPrefixOrder(Term term1, Term term2, int r);
// print function
		void print();
// get weight function
		int getWeight();
// get query function
		string getQuery();
// make autocomplete a friend class
		friend class Autocomplete;
		friend ostream &operator<<(ostream &out, Term &T);
// make private variables
	private:
		string query;
		long weight;
};

#endif
