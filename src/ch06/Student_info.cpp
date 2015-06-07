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

gradebook extract_fails(gradebook& students) {
	// // double-pass solution
	// gradebook fail;
	// remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
	// // remove_copy_if(start, end, destination, predicate) copies all the elements in
	// //		[start, end) to the destination, except those elements for which the given
	// //		predicate is true.  This effectively makes a copy of students containing
	// //		only the failing students.

	// students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
	// // remove_if(start, end, predicate) replaces all elements in [start, end) where the
	// //		given predicate is true with the next element for which it is not true, and
	// //		then returns the iterator representing the new past-the-end element, which
	// //		is passed as the starting iterator to the erase() member function of students.
	// //		The elements past this new past-the-end element still exist, however, so the
	// //		erase() function must be called to finalize the erasure.
	// // erase(start, end) destroys all elements of students starting from 'start' all the
	// //		way to the end.  This completes the operation of removing all the failing
	// //		students from the students container, leaving us with a container with only
	// //		the passing students.
	
	// single-pass solution
	gradebook::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
	// stable_partition(start, end, predicate) rearranges the sequence given by [start, end)
	//		according to the predicate, but keeps them in order aside from that, and returns
	//		an iterator past the last element satisfying the predicate
	gradebook fail(iter, students.end());
	// constructs a new container with the elements from iter to students.end()
	students.erase(iter, students.end());
	// destroys the elements that we moved over to fail

	return fail;
}