#include "analysis.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<Student_info> did, didnt;
	Student_info student;

	// read all records, separating based on whether all homework was done
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

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
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
					optimistic_median_analysis, did, didnt);

	return 0;
}