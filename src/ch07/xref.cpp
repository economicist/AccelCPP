#include "xref.h"

using std::map;
using std::string;
using std::vector;
using std::istream;

// find all the lines that refer to each word in the input
// default for find_words is split() as stated in xref.h
map<string, vector<int> >
		xref(istream& in, vector<string> find_words(const string&)) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;
	// each string is paired with an integer vector stating which line #s
	//		each string is found in.

	// read the next line
	while(getline(in, line)) {
		++line_number;

		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
		for(vector<string>::const_iterator it = words.begin();
				it != words.end(); ++it) {
			ret[*it].push_back(line_number);
		}
	}

	return ret;
}