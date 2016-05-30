#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> combination;

        int n = nums.size();
        for (int k = 0; k <= n; ++k)
        	combineNext(result, combination, nums, k,  0);
        return result;

    }

private:
    void combineNext(vector<vector<int>> &result, vector<int> &combination,
    	vector<int> &nums, int k, int start) {
    	int n = nums.size();
    	if (k == 0) {
        	result.push_back(combination);
        	return;
    	}
    	int end = n - k;
    	for (int i = start; i <= end; ++i) {
        	combination.push_back(nums[i]);
        	combineNext(result, combination, nums, k - 1, i + 1);
        	combination.pop_back();
    	}
	}
};

int main() {

	Solution solution;

	vector<int> nums({ 3, 2, 1});
	vector<vector<int>> result = solution.subsets(nums);
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