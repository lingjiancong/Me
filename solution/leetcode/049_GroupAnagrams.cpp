#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using std::vector;
using std::string;
using std::unordered_map;
using std::endl;
using std::cout;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, std::multiset<string>> groups;

		for (string s : strs) {
			string t(s);
			std::sort(t.begin(), t.end());
			groups[t].insert(s);
		}

		vector<vector<string>> anagrams;
		for (auto group : groups) {
			vector<string> anagram(group.second.begin(), group.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
};

