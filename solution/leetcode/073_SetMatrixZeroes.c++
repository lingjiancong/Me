#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        	return;
        int n = matrix[0].size();

        int col0 = 1;
        for (int i = 0; i < m; ++i) {
        	if (matrix[i][0] == 0)
        		col0 = 0;
        	for (int j = 1; j < n; ++j) {
        		if (matrix[i][j] == 0)
        			matrix[i][0] = matrix[0][j] = 0;
        	}
        }

        for (int i = m - 1; i >= 0; i--) {
        	for (int j = n - 1; j >= 1; j--) {
        		if (matrix[i][0] == 0 || matrix[0][j] == 0)
        			matrix[i][j] = 0;
        	}
        	if (col0 == 0)
        		matrix[i][0] = 0;
        }
    }
};

int main() {

	vector<vector<int>> matrix({ {2, 0, 2, 0}, {1, 1, 1, 1}, {1, 1, 2, 0}, {2, 2, 0, 2} });
	Solution solution;


	int m = matrix.size();
	if (m == 0)
		return 0;
	int n = matrix[0].size();

	for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        	cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

	solution.setZeroes(matrix);
	for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        	cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}