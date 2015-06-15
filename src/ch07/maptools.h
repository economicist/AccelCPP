#ifndef GUARD_maptools_h
#define GUARD_maptools_h

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector< std::pair<std::string, int> > sort_map_by_value(const std::map<std::string, int>&);
bool compare_pair(const std::pair<std::string, int>&, const std::pair<std::string, int>&);

#endif