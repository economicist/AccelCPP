#include <iostream>
#include <vector>
#include <string>
#include "frame.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printStrings(const vector<string>&);

int main() {
	vector<string> p;
	p.push_back("this is the");
	p.push_back("first vector");
	p.push_back("that we will");
	p.push_back("using.");

	vector<string> q;
	q.push_back("this is");
	q.push_back("a second vector");
	q.push_back("of strings");

	vector<string> r;
	r.push_back("how doth the");
	r.push_back("little crocodile");
	r.push_back("obscure his");
	r.push_back("shining");
	r.push_back("tail?");

	vector<string> pFramed = frame(p);
	vector<string> qFramed = frame(q);
	vector<string> rFramed = frame(r);

	printStrings(hcat(p, frame(vcat(q, r))));
}

void printStrings(const vector<string>& v) {
	for (vector<string>::const_iterator row = v.begin(); row != v.end(); ++row)
		cout << *row << endl;
}