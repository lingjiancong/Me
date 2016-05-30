#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
        	return false;
        int n = matrix[0].size();
        if (n == 0)
        	return false;

        int leftM = 0, rightM = m - 1;
        while (leftM <= rightM) {
        	int midM = (leftM + rightM) / 2;
        	if (matrix[midM][0] > target)
        		rightM = midM - 1;
        	else if (matrix[midM][n - 1] < target)
        		leftM = midM + 1;
        	else 
        		return binarySearch(matrix[midM], target);

        }
        return false;
    }

private:
	bool binarySearch(vector<int> &v, int target) {
		int m = v.size();
		if (m == 0)
			return false;
		int left = 0, right = m - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] < target) {
				left = mid + 1;
			}
			else if (v[mid] > target) {
				right = mid - 1;
			}
			else
				return true;
		}
		return false;
	}
};

int main() {

	vector<vector<int> > matrix({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} });

	Solution solution;

	int target = 2;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 5;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 16;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 15;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 23;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 7;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = -7;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;

	target = 57;
	cout << "find " << target << " : " << solution.searchMatrix(matrix, target);
	cout << endl;


	return 0;
}