#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();	// get rid of previous contents

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so input will work for the next student
		in.clear();
	}
	return in;
}