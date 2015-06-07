#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include "Student_info.h"

bool did_all_hw(const Student_info&);
double analyze(const gradebook&,
						double analysis(const Student_info&));
void write_analysis(std::ostream& out, const std::string& name,
					double analysis(const gradebook&),
					const gradebook&,
					const gradebook&);

#endif