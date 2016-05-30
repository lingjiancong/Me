#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
	int totalNQueens(int n) {
		// col, row + col, n - 1 + row - col
		//vector<bool> flagCol(n, true), flag45(2 * n - 1, true), flag135(2 * n - 1, true);
		int total = 0;

		//totalNQueens(total, n, 0, flagCol, flag45, flag135);

		vector<bool> flag(n + 2 * n - 1 + 2 * n - 1, true);
		totalNQueens(total, n, 0, flag);

		return total;

	}

private:
	void totalNQueens(int &total, int n, int row, vector<bool> &flagCol, vector<bool> &flag45, vector<bool> &flag135) {
		if (row == n) {
			++total;
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (flagCol[i] && flag45[row + i] && flag135[n - 1 + row - i]) {
				flagCol[i] = false;
				flag45[row + i] = false;
				flag135[n - 1 + row - i] = false;

				totalNQueens(total, n, row + 1, flagCol, flag45, flag135);

				flagCol[i] = true;
				flag45[row + i] = true;
				flag135[n - 1 + row - i] = true;
			}
		}
	}

	void totalNQueens(int &total, int n, int row, vector<bool> &flag) {
		if (row == n) {
			++total;
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (flag[i] && flag[n + row + i] && flag[4 * n - 2 + row - i]) {
				flag[i] = false;
				flag[n + row + i] = false;
				flag[4 * n - 2 + row - i] = false;

				totalNQueens(total, n, row + 1, flag);

				flag[i] = true;
				flag[n + row + i] = true;
				flag[4 * n - 2 + row - i] = true;
			}
		}
	}
};

int main() {
	Solution solution;
	std::cout << solution.totalNQueens(15) << std::endl;
	return 0;
}