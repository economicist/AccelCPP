#ifndef GUARD_string_h
#define GUARD_string_h

#include <vector>		// std::vector
#include <string>		// std::string
#include <algorithm>	// find_if(), search(), find()
#include <cctype>		// isalnum(), isalpha()

bool space(char);
bool not_space(char);
std::vector<std::string> split(const std::string&);
std::string strip_end_punct(const std::string&);
bool is_palindrome(const std::string&);
std::vector<std::string> find_urls(const std::string&);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
bool not_url_char(char);

#endif