#include <iostream>
#include <vector>
using std::vector;
using std::endl;
using std::cout;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();

		vector<int> row(n, 0);
		for (int i = 0; i < n; ++i) {
			if (obstacleGrid[0][i] == 0)
				row[i] = 1;
			else if (obstacleGrid[0][i] == 1)
				break;
		}
		vector<int> column(m, 0);
		for (int i = 0; i < m; ++i) {
			if (obstacleGrid[i][0] == 0)
				column[i] = 1;
			else if (obstacleGrid[i][0] == 1)
				break;
		}

		for (int i = 1; i < m; ++i) {
			row[0] = column[i];
			for (int j = 1; j < n; ++j) {
				if (obstacleGrid[i][j] == 0)
					row[j] += row[j - 1];
				else if (obstacleGrid[i][j] == 1)
					row[j] = 0;
			}
		}
		return row[n - 1];
	}
};

class Solution2 {
public:
	int uniquePaths(int m, int n) {
		const int size = 101;
		int matrix[size][size] = { 0 };
		matrix[1][0] = 1;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
			}
		}
		return matrix[m][n];
	}
};

int main() {
	Solution solution;
	cout << solution.uniquePaths(2, 4) << endl;
	return 0;
}