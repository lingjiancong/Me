#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty() && p.empty())
			return true;

		if (p.size() > 1 && p[1] == '*') {
			return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
		}
		else if (!p.empty()){
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}

		return false;
	}
};

int main()
{
	Solution solution;
	string s = "aaa";
	string p = "a*";
	cout << solution.isMatch(s, p) << endl;
	return 0;
}