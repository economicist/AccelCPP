#include <string>
#include <vector>
#include "frame.h"
#include "kwic.h"
#include "split.h"

using std::string;
using std::vector;

Phrase_pair rotatePhrase(const Phrase_pair& pp) {
	Phrase_pair ret;
	ret.left = pp.left;
	ret.right.push_back(pp.left.back());
	ret.left.pop_back();
	for (vector<string>::const_iterator word = pp.right.begin(); word != pp.right.end(); ++word) {
		ret.right.push_back(*word);
	}
	return ret;
}

Phrase_pair_collection phraseRotations(const string& s) {
	Phrase_pair_collection ret;
	Phrase_pair pp;
	pp.left = split(s);
	ret.lWidth = 0;
	ret.rWidth = s.size();
	vector<string>::size_type numWords = pp.left.size();
	for (vector<string>::size_type i = 0; i != numWords; ++i) {
		pp = rotatePhrase(pp);
		ret.pairs.push_back(pp);
		string::size_type lWidth = vecstr2string(pp.right).size();
		string::size_type rWidth = vecstr2string(pp.left).size();
		if (lWidth > ret.lWidth)
			ret.lWidth = lWidth;
		if (rWidth > ret.rWidth)
			ret.rWidth = rWidth;
	}
	return ret;
}

Phrase_pair_collection append(const Phrase_pair_collection& ppc1, const Phrase_pair_collection& ppc2) {
	Phrase_pair_collection ret = ppc1;
	if (ppc1.pairs.size() == 0)
		return ppc2;
	for (vector<Phrase_pair>::const_iterator pair = ppc2.pairs.begin(); pair != ppc2.pairs.end(); ++pair)
		ret.pairs.push_back(*pair);
	if (ppc2.lWidth > ppc1.lWidth)
		ret.lWidth = ppc2.lWidth;
	if (ppc2.rWidth > ppc2.rWidth)
		ret.rWidth = ppc2.rWidth;
	return ret;
}

string vecstr2string(const vector<string>& v) {
	string ret = "";
	for (vector<string>::const_iterator word = v.begin(); word != v.end(); ++word)
		ret += (word == v.begin() ? "" : " ") + *word;
	return ret;
}

bool compare(const Phrase_pair& pp1, const Phrase_pair& pp2) {
	return pp1.right < pp2.right;
}