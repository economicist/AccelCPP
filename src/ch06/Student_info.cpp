#include "Student_info.h"

using std::istream;
using std::list;
using std::vector;

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

gradebook extract(gradebook& students, bool criterion(const Student_info&)) {
	gradebook::iterator iter = 
		stable_partition(students.begin(), students.end(), criterion);
	// stable_partition(start, end, predicate) rearranges the sequence given by [start, end)
	//		according to the predicate, but keeps them in order aside from that, and returns
	//		an iterator past the last element satisfying the predicate
	gradebook other(iter, students.end());
	// constructs a new container with the elements from iter to students.end()
	students.erase(iter, students.end());
	// destroys the elements that we moved over to fail
	return other;
}