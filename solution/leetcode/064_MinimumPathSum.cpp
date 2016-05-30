#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		if (n == 0)
			return 0;

		vector<int> row(n, grid[0][0]);
		for (int i = 1; i < n; ++i)
			row[i] = row[i - 1] + grid[0][i];

		for (int i = 1; i < m; ++i) {
			row[0] += grid[i][0];
			for (int j = 1; j < n; ++j) {
				row[j] = (row[j] > row[j - 1] ? row[j - 1] : row[j]) + grid[i][j];
			}
		}
		return row[n - 1];
	}
};

int main() {
	return 0;
}