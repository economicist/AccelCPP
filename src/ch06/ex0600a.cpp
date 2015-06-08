#include "analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	gradebook did;
	Student_info student;

	// read all records, separating based on whether all homework was done
	while (read(cin, student)) {
		did.push_back(student);
	}

	gradebook didnt = extract(did, did_all_hw);

	// check that both groups contain data
	if (did.empty()) {
		cout << "Nobody did all their homework." << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Everyone did all their homework." << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", grade_aux, did, didnt);
	write_analysis(cout, "average", average_grade, did, didnt);
	write_analysis(cout, "median of homework turned in",
					optimistic_median, did, didnt);

	return 0;
}