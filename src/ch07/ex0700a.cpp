#include <iostream>		// std::cout, std::cin, std::endl
#include <string>		// std::string
#include <map>			// std::map
#include "string.h"		// strip()

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;

int main() {
	string s;
	map<string, int> counters;	// store each word in an associative container

	// read the input, keeping track of each word and an associated container
	while (cin >> s) {
		s = strip_end_punct(s);
		++counters[s];
	}

	// write the words and associated counts
	for (map<string, int>::const_iterator it = counters.begin();
			it != counters.end(); ++it) {
		cout << (*it).first << "\t" << (*it).second << endl;
	}

	return 0;
}