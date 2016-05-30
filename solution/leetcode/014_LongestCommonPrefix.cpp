#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string comPre = strs[0];
		for (int i = 1; i < strs.size(); ++i) {
			string sComPre = "";
			int less = comPre.size() > strs[i].size() ? strs[i].size() : comPre.size();
			for (int j = 0; j < less; ++j) {
				if (strs[i][j] == comPre[j])
					sComPre += comPre[j];
				else
					break;
			}
			comPre = sComPre;
		}
		return comPre;
	}
};