#include "vecstats.h"

using std::domain_error;
using std::vector;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
// because we have to sort it in order to find the median
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// compute the mean of a vector<double>
// note that since we don't need to change the argument vector in
// order to compute its average, we can use a reference to it rather
// than a copy of it
double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}