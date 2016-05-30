#include <iostream>
using namespace std;

// dynamic programming, that is not true, did you believe?
// yeah, 2016-05-26, morning 12:28
class Solution {
public:
	bool isScramble(string s1, string s2) {

		int n1 = s1.size(), n2 = s2.size();
		if (n1 != n2)
			return false;
		if (s1 == s2) 
			return true;

		const int N = 26;
		int val[N] = {0};
		for (int i = 0; i < n1; ++i) {
			val[s1[i] - 'a']++;
			val[s2[i] - 'a']--;
 		}
 		for (int i = 0; i < N; ++i) {
 			if (val[i] != 0)
 				return false;
 		}
 		for (int i = 1; i < n1; ++i) {
 			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
 				return true;
 			if (isScramble(s1.substr(0, i), s2.substr(n1 - i)) && isScramble(s1.substr(i), s2.substr(0, n1 - i)))
 				return true;
 		}
 		return false;


	}

};

int main() {
	Solution solution;

	string s1 = "great", s2 = "rgeta";
	cout << "s1 = " << s1 << " -- s2 = " << s2;
	cout << " isScramble: " << solution.isScramble(s1, s2) << endl;

	s1 = "great", s2 = "trgea";
	cout << "s1 = " << s1 << " -- s2 = "  << s2;
	cout << " isScramble: " << solution.isScramble(s1, s2) << endl;

	s1= "great", s2 = "etagr";
	cout << "s1 = " << s1 << " -- s2 = " << s2;
	cout << " isScramble: " << solution.isScramble(s1, s2) << endl;

	return 0;
}