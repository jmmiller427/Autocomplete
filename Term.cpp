#include <iostream>
#include <string>
#include <vector>
#include "Term.h"

using namespace std;

// Term constructor
Term::Term()
{
// set query and weight
	query = "Term";
	weight = 0;
}

Term::Term(string q, long w)
{
// set query to query
	query = q;
// set weight to weight
	weight = w;
}

// reverse weight order
int Term::byReverseWeightOrder(Term term1, Term term2)
{
// if term 1 weight is greater than term 2 weight
	if (term1.getWeight() > term2.getWeight())
	{
// return 1
		return 1;
	}

// if term 1 weight is equal to term 2 weight
	if (term1.getWeight() == term2.getWeight())
	{
// return 0
		return 0;
	}

// if term 1 weight less than term 2 weight
	if (term1.getWeight() < term2.getWeight())
	{
// return -1
		return -1;
	}
}

// compare to function
int Term::compareTo(Term term1, Term term2)
{
// if term 1 query greater than term 2 query
	if (term1.getQuery() > term2.getQuery())
	{
// return 1
		return 1;
	}

// if term 1 query equals term 2 query
	if (term1.getQuery() == term2.getQuery())
	{
// return 0
		return 0;
	}

// if term 1 query less than term 2 query
	if (term1.getQuery() < term2.getQuery())
	{
// return -1
		return -1;
	}
}

// prefix order
int Term::byPrefixOrder(Term term1, Term term2, int r)
{
// set substring values to the substring of each term
	string substr_term1 = (term1.getQuery()).substr(0, r);
	string substr_term2 = (term2.getQuery()).substr(0, r);

// if substring 1 greater than substring 2
	if (substr_term1 > substr_term2)
	{
// return 1
		return 1;
	}

// if substring 1 equal to substring 2
	if (substr_term1 == substr_term2)
	{
// return 0
		return 0;
	}

// if substring 1 less than substring 2
	if (substr_term1 < substr_term2)
	{
// return -1
		return -1;
	}
}

// print
void Term::print()
{
// output the message to print
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
