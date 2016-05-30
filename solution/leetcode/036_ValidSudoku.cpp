#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool row = validRow(board);
		if (!row)
			return false;
		bool column = validColumn(board);
		if (!column)
			return false;
		bool subbox = validSubbox(board);
		if (!subbox)
			return false;
		return true;
	}

	bool validRow(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); ++i) {
			vector<int> row(9, 0);
			for (int j = 0; j < board[i].size(); ++j) {
				char c = board[i][j];
				if (c != '.') {
					int index = c - '0' - 1;
					if (row[index] == 1)
						return false;
					else
						row[index] = 1;
				}
			}
		}
		return true;
	}

	bool validColumn(vector<vector<char>>& board) {
		int columns = board[0].size();
		for (int i = 0; i < columns; ++i) {
			vector<int> column(9, 0);
			for (int j = 0; j < board.size(); ++j) {
				char c = board[j][i];
				if (c != '.') {
					int index = c - '0' - 1;
					if (column[index] == 1)
						return false;
					else
						column[index] = 1;
				}
			}
		}
		return true;
	}

	bool validSubbox(vector<vector<char>>& board) {
		int threshold = 9;
		for (int count = 0; count < threshold; ++count) {
			int start_i = count / 3 * 3;
			int start_j = count % 3 * 3;
			vector<int> subbox(9, 0);
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					char c = board[start_i + i][start_j + j];
					if (c != '.') {
						int index = c - '0' - 1;
						if (subbox[index] == 1)
							return false;
						else
							subbox[index] = 1;
					}
				}
			}
		}
		return true;
	}
};

int main() {
	return 0;
}