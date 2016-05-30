#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;



class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0, cache = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ')
				count++;
			else {
				if (count != 0)
					cache = count;
				count = 0;
			}
		}
		if (count == 0)
			return cache;
		return count;
	}
};

int main() {
	string s1 = " 123";
	string s2 = "123 1234  ";
	Solution solution;
	cout << solution.lengthOfLastWord(s1) << endl;
	cout << solution.lengthOfLastWord(s2) << endl;
	return 0;
}