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
		Term();
		Term(string query, long weight);

		int byReverseWeightOrder(Term term1, Term term2);

		int compareTo(Term term1, Term term2);

		int byPrefixOrder(Term term1, Term term2, int r);

		void print();

		int getWeight();

		string getQuery();

		friend class Autocomplete;
		friend ostream &operator<<(ostream &out, Term &T);

	private:
		string query;
		long weight;
};

#endif
