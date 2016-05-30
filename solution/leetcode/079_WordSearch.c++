#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0)
        	return false;
        if (word == "")
        	return true;
        int n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		char c = word[0];
        		if (c == board[i][j]) {
        			flag[i][j] = true;
        			bool result = backtrack(board, i - 1, j, word.substr(1), flag)
        				|| backtrack(board, i + 1, j, word.substr(1), flag)
        				|| backtrack(board, i, j - 1, word.substr(1), flag)
        				|| backtrack(board, i, j + 1, word.substr(1), flag);
        			if (result)
        				return true;
        			flag[i][j] = false;
        		}
        	}
        }
        return false;
    }

private:
	bool backtrack(vector<vector<char>> &board, int i, int j, string word,
	 vector<vector<bool>> &flag) {
		if (word == "")
			return true;
		int m = board.size(), n = board[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return false;
		}
		if (flag[i][j] == true || board[i][j] != word[0]) {
			return false;
		}

		flag[i][j] = true; 
		bool result =  backtrack(board, i - 1, j, word.substr(1), flag)
    				|| backtrack(board, i + 1, j, word.substr(1), flag)
    				|| backtrack(board, i, j - 1, word.substr(1), flag)
    				|| backtrack(board, i, j + 1, word.substr(1), flag);
    	if (result)
    		return true;
    	flag[i][j] = false;
    	return false;
	}
};

int main() {
	vector<vector<char>> board = { { 'a', 'b', 'c', 'e' },
								  { 's', 'f', 'c', 's' },
								  { 'a', 'd', 'e', 'e' }
								};

	Solution solution;

	string word = "abcce";
	cout << word << " exist? = " << solution.exist(board, word) << endl;

	word = "see";
	cout << word << " exist? = " << solution.exist(board, word) << endl;

	word = "a";
	cout << word << " exist? = " << solution.exist(board, word) << endl;

	word = "abcb";
	cout << word << " exist? = " << solution.exist(board, word) << endl;
	return 0;
}