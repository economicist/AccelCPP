#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::list;
using std::vector;
using std::sort;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

list<Student_info> sortByName(list<Student_info>& s) {
	list<Student_info> ret = s;
	ret.sort(compare);
	return ret;
}

vector<Student_info> sortByName(vector<Student_info>& s) {
	vector<Student_info> ret = s;
	sort(ret.begin(), ret.end(), compare);
	return ret;
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

gradebook extract_fails(gradebook& students) {
	gradebook fail;
	gradebook::iterator iter = students.begin();
	
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	return fail;
}