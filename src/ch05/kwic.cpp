#include <string>
#include <vector>
#include "kwic.h"
#include "split.h"

using std::string;
using std::vector;

struct String_pair {
	string left, right;
};

String_pair rotateLine(const string& left) {
	String_pair ret;
	string leftPiece, rightPiece;
	vector<string> v = split(s);
	ret.left = v.back();
	v.pop_back();
	for (vector<string>::iterator word = v.begin(); word != v.end(); ++word)
		ret = ret + " " + *word;
	return ret;
}

vector<String_pair> lineRotations(const string& s) {
	vector<string> ret;
	string str = s;
	vector<string>::size_type len = split(s).size();
	for (vector<string>::size_type i = 0; i != len; ++i) {
		ret.push_back(str);
		str = rotate(str);
	}
	return ret;
}

vector<string> allRotations(const vector<string>& v) {
	vector<string> ret;
	for (vector<string>::size_type line = v.begin(); line != v.end(); ++line) {
		vector<string> rotations = lineRotations(*line);

	}
	return ret;
}