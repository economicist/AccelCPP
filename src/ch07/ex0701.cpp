#include <iostream>		// std::cout, std::cin, std::endl
#include "maptools.h"	// sort_map_by_value()
#include "string.h"		// strip()

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
	string s;
	map<string, int> counters;	// store each word in an associative container

	// read the input, keeping track of each word and an associated container
	while (cin >> s) {
		s = strip_end_punct(s);
		++counters[s];
	}

	vector< pair<string, int> > sorted_counters = sort_map_by_value(counters);
	// write the words and associated counts
	for (vector< pair<string, int> >::const_iterator it = sorted_counters.begin();
			it != sorted_counters.end(); ++it) {
		cout << (*it).first << "\t" << (*it).second << endl;
	}

	return 0;
}