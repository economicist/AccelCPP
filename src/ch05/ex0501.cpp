#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "kwic.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main() {
	vector<string> poem;
	poem.push_back("how doth the little crocodile");
	poem.push_back("obscure his shining tail");
	poem.push_back("and pour the waters of the nile");
	poem.push_back("on every golden scale");
	poem.push_back("how cheerfully he seems to grin");
	poem.push_back("how neatly spreads his claws");
	poem.push_back("and welcomes little fishes in");
	poem.push_back("with gently smiling jaws");
	
	vector<string> rot = rotations(s);
	for (vector<string>::iterator line = rot.begin(); line != rot.end(); ++line)
		cout << *line << endl;
	cout << endl;

	sort(rot.begin(), rot.end());
	for (vector<string>::iterator line = rot.begin(); line != rot.end(); ++line)
		cout << *line << endl;
	
	return 0;	
}