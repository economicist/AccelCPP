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

// Exercise 6-6
double analyze(const gradebook& students,
						double analysis_type(const Student_info&)) {
	// analysis can be any of {grade_aux, average_grade, optimistic_median}
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), analysis_type);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
					double analysis_type(const Student_info&),
					const gradebook& did,
					const gradebook& didnt)
{
	out << name << ": median(did) = " << analyze(did, analysis_type)
				<< ", median(didnt) = " << analyze(didnt, analysis_type) << endl;
}