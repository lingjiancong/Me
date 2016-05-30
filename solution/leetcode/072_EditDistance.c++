#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int n = word1.size(), m = word2.size();
    	if (n == 0)
    		return m;
    	if (m == 0)
    		return n;
    	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));

    	for (int i = 0; i < m + 1; ++i) {
    		d[0][i] = i;
    	}
    	for (int j = 0; j < n + 1; ++j) {
    		d[j][0] = j;
    	}

    	for (int i = 1; i < n + 1; ++i) {
    		for (int j = 1; j < m + 1; ++j) {
    			int n_m_1 = d[i][j - 1] + 1;
    			int n_1_m = d[i - 1][j] + 1;
    			int n_1_m_1 = d[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
    			int min = n_m_1 > n_1_m ? n_1_m : n_m_1;
    			d[i][j] = min > n_1_m_1 ? n_1_m_1 : min;
    		}
    	}

    	return d[n][m];
    }
};

int main() {
	Solution solution;

	string word1 = "abc", word2 = "abc";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	word1 = "abc", word2 = "abcd";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	word1 = "abcdd", word2 = "abcd";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	word1 = "aa", word2 = "aba";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	word1 = "abdac", word2 = "abdacd";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	word1 = "abcda", word2 = "ssfdsd";
	cout << "word1: " << word1 << " --> " << "word2: " << word2 << " -- " << solution.minDistance(word1, word2) << endl;

	return 0;
}