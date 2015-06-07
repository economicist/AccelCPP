#include "analysis.h"

using std::vector;
using std::string;
using std::domain_error;
using std::ostream;
using std::endl;

bool did_all_hw(const Student_info& s) {
	return (find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end();
	// return a bool saying whether we found a zero in the student's homework scores
}

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did)
				<< ", median(didnt) = " << analysis(didnt) << endl;
}