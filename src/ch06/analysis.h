#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include "Student_info.h"

bool did_all_hw(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream& out, const std::string& name,
					double analysis(const std::vector<Student_info>&),
					const std::vector<Student_info>&,
					const std::vector<Student_info>&);

#endif