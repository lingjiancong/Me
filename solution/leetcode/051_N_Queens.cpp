#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::endl;
using std::cout;

class Solution {
private:
	struct Cell {
		bool value;
		bool set;
		Cell() : value(false), set(false) {};
		bool isSet() { return set; }
	};

	vector<vector<Cell>> cells;

	void solveNQueens(vector<vector<string>> &res, int row, int n) {
		if (row == n) {
			vector<string> result(n);
			for (int i = 0; i < n; ++i)  {
				string s(n, ' ');
				for (int j = 0; j < n; ++j) {
					s[j] = cells[i][j].value ? 'Q' : '.';
				}
				result[i] = s;
			}
			res.push_back(result);
			return;
		}
		vector<vector<Cell>> snapshot(cells);

		for (int i = 0; i < n; ++i) {
			if (set(row, i, n))
				solveNQueens(res, row + 1, n);
			cells = snapshot;
		}
	}

	bool set(int row, int column, int n) {
		if (cells[row][column].set)
			return false;
		cells[row][column].set = true;
		cells[row][column].value = true;

		for (int i = 0; i < n; ++i) {
			cells[row][i].set = true;
			cells[i][column].set = true;
		}

		// slash
		int i = row, j = column;
		// upper left
		while (i >= 0 && j >= 0) {
			cells[i][j].set = true;
			--i; --j;
		}
		// upper right
		i = row; j = column;
		while (i < n && j >= 0) {
			cells[i][j].set = true;
			++i; --j;
		}
		// lower left
		i = row; j = column;
		while (i >= 0 && j < n) {
			cells[i][j].set = true;
			--i; ++j;
		}
		// lower right
		i = row; j = column;
		while (i < n && j < n) {
			cells[i][j].set = true;
			++i; ++j;
		}
		return true;
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;

		for (int i = 0; i < n; ++i) {
			vector<Cell> vc(n);
			cells.push_back(vc);
		}

		int row = 0;
		solveNQueens(result, row, n);
		return result;
	}
};

int main() {
	Solution solution;
	vector <vector<string>> result = solution.solveNQueens(12);
	cout << "size = " << result.size() << endl;
	//cout << "[" << endl;
	for (int i = 0; i < result.size(); ++i) {
		//cout << "  [" << endl;
		for (int j = 0; j < result[i].size(); ++j) {
			//cout << result[i][j] << endl;
		}
		//cout << "  ]" << endl;
	}
	cout << endl;

	return 0;
}