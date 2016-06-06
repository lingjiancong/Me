#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isInterleave1(string s1, string s2, string s3) {
    	int m = s1.size(), n = s2.size();
    	if (m + n != s3.size())
    		return false;
    	//cout << "solution begin" << endl;
    	if (m == 0)
    		return s2 == s3;
    	else if (n == 0) 
    		return s1 == s3;
    	vector<vector<bool>> matrix(m + 1, vector<bool>(n + 1, false));

    	matrix[0][0] = true;

    	for (int i = 1; i <= m; ++i) {
    		if (matrix[i - 1][0] && s1[i - 1] == s3[i - 1])
    			matrix[i][0] = true;
    	}
    	for (int i = 1; i <= n; ++i) {
    		if (matrix[0][i - 1] && s2[i - 1] == s3[i - 1])
    			matrix[0][i] = true; 
    	}
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			if ( (matrix[i - 1][j] && s1[i - 1] == s3[i + j - 1])
    			     || (matrix[i][j - 1] && s2[j - 1] == s3[i + j - 1]) )
    				matrix[i][j] = true;
    		}
    	}

    	return matrix[m][n];
    }

    bool isInterleave(string s1, string s2, string s3) {
    	int m = s1.size(), n = s2.size();
    	if (m + n != s3.size())
    		return false;
    	//cout << "solution begin" << endl;
    	if (m == 0)
    		return s2 == s3;
    	else if (n == 0) 
    		return s1 == s3;

    	vector<bool> v(n + 1, false);
    	v[0] = true;
    	for (int i = 1; i <= n; ++i) {
    		if (v[i - 1] && s2[i - 1] == s3[i - 1])
    			v[i] = true;
    	}
    	for (int k = 1; k <= m; ++k) {
    		if (v[0] && s1[k - 1] == s3[k - 1])
    			v[0] = true;
    		else
    			v[0] = false;
    		for (int j = 1; j <= n; ++j) {
    			if ( (v[j] && s1[k - 1] == s3[k + j - 1])
    			     || (v[j - 1] && s2[j - 1] == s3[k + j - 1]) )
    				v[j] = true;
    			else
    				v[j] = false;
    		}
    	}
    	return v[n];
    }
};

int main() {
	Solution solution;
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	cout << s3 << " " << solution.isInterleave(s1, s2, s3) << endl;

	s3 = "aadbbbaccc";
	cout << s3 << " " << solution.isInterleave(s1, s2, s3) << endl;

	s1 = "aa", s2 = "ab", s3 = "abaa";
	cout << s3 << " " << solution.isInterleave(s1, s2, s3) << endl;

	return 0;
}