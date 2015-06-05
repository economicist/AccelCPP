#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "kwic.h"
#include "split.h"

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

	Phrase_pair_collection ppc;
	for (vector<string>::iterator phrase = poem.begin(); phrase != poem.end(); ++phrase)
		ppc = append(ppc, phraseRotations(*phrase));

	sort(ppc.pairs.begin(), ppc.pairs.end(), compare);

	for (vector<Phrase_pair>::iterator pair = ppc.pairs.begin(); pair != ppc.pairs.end(); ++ pair) {
		string str_left = vecstr2string((*pair).left);
		string str_right = vecstr2string((*pair).right);
		cout << string(ppc.lWidth - str_left.size(), ' ') + str_left;
		cout << "     " << str_right << endl;
	}

	return 0;	
}