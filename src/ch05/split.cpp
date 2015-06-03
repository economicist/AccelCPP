#include <string>
#include <vector>
#include <cctype>
#include "split.h"

using std::string;
using std::vector;

vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		//invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;
		// now i = position of the first letter of next word
		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j) is a space
		while (j != s.size() && !isspace(s[j]))
			j++;
		// now j = end of the input string *or* the space following next word
		if (i != j) {
			// if i and j are not the same position, then there is a nonempty string
			// in between, so we can place it in the vector of strings
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j-i));
			i = j;	// move i to the position after the word we just pushed to ret
		}
	}
	return ret;
}