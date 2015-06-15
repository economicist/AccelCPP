#include "maptools.h"

using std::map;
using std::pair;
using std::sort;
using std::vector;
using std::string;
using std::cout; using std::endl;

vector< pair<string, int> > sort_map_by_value(const map<string, int>& m) {
	// create a working vector that we can sort easily
	vector< pair<string, int> > ret;
	for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
		ret.push_back(*it);

	// sort the return vector by value
	sort(ret.begin(), ret.end(), compare_pair);

	return ret;
}

bool compare_pair(const pair<string, int>& p, const pair<string, int>& q) {
	return p.second > q.second;
}