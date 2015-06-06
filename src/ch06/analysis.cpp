#include "analysis.h"

bool did_all_hw(const Student_info& s) {
	return (find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end();
	// return a bool saying whether we found a zero in the student's homework scores
}