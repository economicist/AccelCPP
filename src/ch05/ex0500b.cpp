#include "split.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

int main() {
	string s;
	// read and split each line of input
	while (getline(cin, s)) {
		vector<string> v = split(s);
		// write each word in v

		for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
			cout << *iter << endl;
	}

	return 0;
}