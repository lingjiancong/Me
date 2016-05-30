#include <iostream>
using namespace std;

const int N = 256;

// code needs simplification
class Solution {	
public:
    string minWindow(string s, string t) {
        int tState[N] = {0};
        int tn = t.size(), countDiff = 0;
        for (int i = 0; i < tn; ++i) {
        	if (tState[t[i]]++ == 0)
        		countDiff++;
        }

        int left = 0, right = 0;
        int sn = s.size();
        while (left < sn) {
        	if (tState[s[left]] > 0)
        		break;
        	left++;
        }
        right = left;

        int sState[N] = {0}, count = 0;
        while (right < sn) {
        	sState[s[right]]++;
        	if (tState[s[right]] != 0 && sState[s[right]] == tState[s[right]])
        		count++;
        	if (count == countDiff)
        		break;
        	right++;
        }

        if (count != countDiff)
        	return "";

        int minLeft = left, minRight = right;
        while (right < sn) {
        	char c = s[left];
        	while (++left < sn && tState[s[left]] == 0)
        		;
        	if (sState[c] > tState[c]) {
        		sState[c]--;
        		if (right - left <= minRight - minLeft) {
        			minLeft = left;
        			minRight = right;
        		}
        	}
        	else {
        		while (++right < sn && s[right] != c)
        			sState[s[right]]++;
        		if (right < sn) {
        			if (right - left <= minRight - minLeft) {
        				minLeft = left;
        				minRight = right;
        			}
        		}
        	}		
        }
        return s.substr(minLeft, minRight - minLeft + 1);
    }
};

int main() {

	Solution solution;

	string s = "adobecodebanc", t = "abc";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	s = "adobecodebanc"; t = "";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	s = "adobecodebanc"; t = "c";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	s = "aa"; t = "aa";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	s = "bbaa"; t = "aba";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	s = "abcabdebac"; t = "cda";
	cout << "s = " << s << " and t = " << t << " -- " << solution.minWindow(s, t) << endl;

	return 0;
}