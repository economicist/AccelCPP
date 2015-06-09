#include "string.h"

using std::string;
using std::vector;

// true if the argument is whitespace, false otherwise
bool space(char c) {
	return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
	return !isspace(c);
}

vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	while (i != str.end()) {
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);	// calls "not_space" on every element
												// in the sequence and stops when it finds whitespace

		// find end of next word
		iter j = find_if(i, str.end(), space);	// calls "space" on every element starting with the
												// last non-whitespace character, and stops when it
												// finds a space
		
		// copy the characters in [i, j) to ret
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

string strip_end_punct(const string& str) {
	if (str == "")
		return str;
	string::const_iterator c = str.end();
	while ( !isalnum( *(c-1) ) ) {
		--c;
	}
	return string(str.begin(), c);
}

bool is_palindrome(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
	// first two arguments are the beginning and end of sequence 1
	// third argument states the beginning of sequence 2
	// equal() compares the two sequences and returns true or false

	// rbegin returns an iterator that starts  with the last
	// element in s and moves backwards to the beginning.
}

vector<string> find_urls(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// look through entire input
	while (b != e) {
		// look for one or more letters followed by "://"
		b = url_beg(b, e);

		// if we found it
		if (b != e) {
			// get the rest of the URL
			iter after = url_end(b, e);
			// remember the URL
			ret.push_back(string(b, after));
			// advance b and check for more URLs on this line
			b = after;
		}
	}
	return ret;
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";
	typedef string::const_iterator iter;

	// i marks where the separator was found;
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
		// first two arguments to search() represent the sequence in which we are looking
		// last two arguments to search() represent the sequence that we are looking for
		// if search() returns the end of the input string, then we did not find the separator
		// in this iteration

		// make sure the separator isn't at beginning or end of the input
		if (i != b && i + sep.size() != e) {
			// beg marks the beginning of the protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;	// tick backwards until you hit an invalid character.
						// then beg will represent the beginning of the protocol-name
			
			// is there at least one appropriate character before and after the separator?
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;	// if we found a protocol-name before and valid text after
							// the separator, return the position of the beginning of the
							// URL candidate that we have found.
		}
		// if the separator we found wasn't part of a URL, advance i past this separator
		i += sep.size();
	}
	return e;	// if we did not find a '://' preceded by a protocol-name
				// and followed by some valid characters, just return the iterator
				// representing the end of the input sequence
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
	return find_if(b, e, not_url_char);
}

bool not_url_char(char c) {
	// characters, in addition to alphanumerics, that can appear in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	// 'static' ensures that this string will be created only the first time
	// that the function is called, and remembered for future invocations

	// see wheter c can appear in a URL and return the negative
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
	// isalnum(c) returns a bool that states whether c is alphanumeric
	// find() looks for 'c' within the group of characters in url_ch, then returns
	// 		a bool that states whether it got all the way to the end without finding one
	// if both are false, then we return 'true' because c is not a url character
}