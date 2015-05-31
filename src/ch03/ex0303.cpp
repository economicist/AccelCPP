#include <iostream>
#include <string>
#include <vector>

using std::cout;	using std::vector;
using std::cin;		
using std::endl;	using std::string;

int main() {
	string word;
	vector<string> uniqueWordList;
	vector<int> occurrences;

	typedef vector<string>::size_type vec_str_sz;

	cout << "Provide an input of words:" << endl;
	
	// examine the input words one at a time
	// add them to the unique word list as they are
	// found, and increment the counter for each
	// word every time a duplicate is detected
	while (cin >> word) {
		// check to see if the word is already in the list
		// and if so, increment the occurrences element
		bool found = false;
		vec_str_sz numUniqueWords = uniqueWordList.size();
		for (vec_str_sz i = 0; i != numUniqueWords; ++i) {
			if (word == uniqueWordList[i]) {
				occurrences[i]++;
				found = true;
				break;
			}
		}
		// If we didn't find the word in the unique word list
		// add it, and then add an element to the occurrences
		// vector with count 1
		if (found == false) {
			uniqueWordList.push_back(word);
			occurrences.push_back(1);
		}
	}

	vec_str_sz numUniqueWords = uniqueWordList.size();
	for (vec_str_sz i = 0; i != numUniqueWords; ++i)
		cout << uniqueWordList[i] << " " << occurrences[i] << endl;

	return 0;
}