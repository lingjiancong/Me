#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::string; 

class Solution {
public:
	int longestValidParentheses(string s) {
		std::stack<int> st_len;
		std::stack<char> st;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				st.push('(');
				st_len.push(0);
			}
			else if (s[i] == ')') {
				if (!st.empty()) {
					char c = st.top();
					if (c == '(') {
						st.pop();
						int  tt = st_len.top();
						tt += 2;
						st_len.pop();
						if (!st_len.empty()) {
							int ttt = st_len.top();
							ttt += tt;
							st_len.pop();
							st_len.push(ttt);
						}
						else
							st_len.push(tt);

					}
				}
				else {
					while (!st.empty())
						st.pop();
					st_len.push(0);
				}
			}
		}
		int longest = 0;
		while (!st_len.empty()) {
			int t = st_len.top();
			if (t > longest)
				longest = t;
			st_len.pop();
		}
		return longest;
	}
};

class Solution1 {
public:
	int longestValidParentheses(string s) {
		int n = s.length(), longest = 0;
		std::stack<int> st;
		for (size_t i = 0; i < n; ++i) {
			if (s[i] == '(') st.push(i);
			else {
				if (!st.empty()) {
					if (s[st.top()] == '(') st.pop();
					else st.push(i);
				}
				else st.push(i);
			}
		}

		if (st.empty()) longest = 0;
		else {
			int a = n, b = 0;
			while (!st.empty()) {
				b = st.top(); st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			longest = max(longest, a);
		}
		return longest;
	}

	int max(int a, int b) {
		return a > b ? a : b;
	}
};


class Solution2 {
public:
	int longestValidParentheses(string s) {
		if (s.length() <= 1) return 0;
		int curMax = 0;
		std::vector<int> longest(s.size(), 0);
		for (size_t i = 1; i < s.length(); ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					longest[i] = (i - 2) >= 0 ? (longest[i - 2] + 2) : 2;
					curMax = max(longest[i], curMax);
				}
				else {
					if (i - longest[i - 1] >= 0 && s[i - longest[i - 1]] == '(') {
						longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 > 0) ? longest[i - longest[i - 1] - 2] : 0);
						curMax = max(longest[i], curMax);
					}
				}
			}
		}
		return curMax;
	}

	int max(int a, int b) {
		return a > b ? a : b;
	}
};

int main() {

	string s = ")()())()())";
	Solution solution;
	cout << solution.longestValidParentheses(s) << endl;
	Solution1 solution1;
	Solution2 solution2;
	cout << solution1.longestValidParentheses(s) << endl;
	//cout << solution2.longestValidParentheses(s) << endl;
	return 0;
}