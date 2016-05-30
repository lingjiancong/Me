#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		permute(result, nums, -1);
		return result;
	}

private:
	void permute(vector<vector<int>> &result, vector<int> nums, int index) {
		int begin = index + 1, size = nums.size();
		if (begin == size) {
			result.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); ++i) {
			swap(nums[begin], nums[i]);
			permute(result, nums, begin);
			swap(nums[begin], nums[i]);
		}
	}

	void swap(int &a, int &b) {
		int t = a;
		a = b;
		b = t;
	}
};

int main()
{
	vector<int> nums({ 3, 3, 0, 0, 2, 3, 2 });
	Solution solution;
	vector<vector<int>> result = solution.permute(nums);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}