#include "xref.h"

using std::map;			using std::cin;
using std::string;		using std::cout;
using std::vector;		using std::endl;

int main() {
	// call xref() using split() by default
	map <string, vector<int> > ret = xref(cin);

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
			it != ret.end(); ++it) {
		// write the word
		cout << (*it).first;
		
		vector<int>::const_iterator line_it = (*it).second.begin();
		while (line_it != (*it).second.end())
			cout << " " << *line_it;

		cout << endl;
	}

	return 0;
}