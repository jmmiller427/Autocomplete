#include <iostream>
#include <string>
#include <vector>
#include "Term.h"

using namespace std;

// Term constructor
Term::Term()
{
	query = "Term";
	weight = 0;
}

Term::Term(string q, long w)
{
	query = q;
	weight = w;
}

// reverse weight order
int Term::byReverseWeightOrder(Term term1, Term term2)
{
	if (term1.getWeight() > term2.getWeight())
	{
		return 1;
	}

	else if (term1.getWeight() == term2.getWeight())
	{
		return 0;
	}

	else if (term1.getWeight() < term2.getWeight())
	{
		return -1;
	}
}

// compare to function
int Term::compareTo(Term term1, Term term2)
{
	if (term1.getQuery() > term2.getQuery())
	{
		return 1;
	}

	else if (term1.getQuery() == term2.getQuery())
	{
		return 0;
	}

	else if (term1.getQuery() < term2.getQuery())
	{
		return -1;
	}
}

// prefix order
int Term::byPrefixOrder(Term term1, Term term2, int r)
{
// set substring values to the substring of each term
	string substr_term1 = (term1.getQuery()).substr(0, r);
	string substr_term2 = (term2.getQuery()).substr(0, r);

	if (substr_term1 > substr_term2)
	{
		return 1;
	}

	else if (substr_term1 == substr_term2)
	{
		return 0;
	}

	else if (substr_term1 < substr_term2)
	{
		return -1;
	}
}

// print
void Term::print()
{
	cout << query << "   " << weight << endl;
}

// get weight
int Term::getWeight()
{
	return weight;
}

// get query
string Term::getQuery()
{
	return query;
}

ostream &operator<<(ostream &out, Term &term)
{
	return out << term.getWeight() << "	" << term.getQuery();
}
