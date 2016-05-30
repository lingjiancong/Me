#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine1(int n, int k) {

    	if (n == k) {
    		vector<int> v(n, 1);
    		for (int i = 0; i < n; ++i) {
    			v[i] = i + 1;
    		}
    		vector<vector<int>> result;
    		result.push_back(v);
    		return result;
    	}
    	if (k == 1) {
    		vector<vector<int>> result;
    		for (int i = 0; i < n; ++i) {
    			result.push_back(vector<int>(1, i + 1));
    		}
    		return result;
    	}

        vector<vector<int>> combinations;

        vector<vector<int>> part1 = combine(n - 1, k);
        vector<vector<int>> part2 = combine(n - 1, k - 1);

        int n2 = part2.size();
        for (int i = 0; i < n2; ++i) {
        	part2[i].push_back(n);
        }

        for (int i = 0; i < n2; ++i) {
        	part1.push_back(part2[i]);
        }
        return part1;
    }

    vector<vector<int>> combine(int n , int k) {
        vector<vector<int>> result;
        int end = n - k + 1;
        vector<int> combination;

        combineNext(result, combination, n, k, 1);
        return result;
    }

    void combineNext(vector<vector<int>> &result, vector<int> &combination,
        int n, int k, int start) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }
        int end = n - k + 1;
        for (int i = start; i <= end; ++i) {
            combination.push_back(i);
            combineNext(result, combination, n, k - 1, i + 1);
            combination.pop_back();
        }
    }
};

int main() {
	Solution solution;

	int n = 4, k = 2;
	vector<vector<int>> result = solution.combine(n, k);
	int row = result.size();
	for (int i = 0; i < row; ++i) {
		cout << "[ ";
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << "  ";
		}
		cout << "]";
		cout << endl;
	}
	return 0;
}