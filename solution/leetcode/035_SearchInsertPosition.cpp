#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] > target)
				end = mid - 1;
			else if (nums[mid] < target)
				start = mid + 1;
			else
				return mid;
		}
		if (nums[start] < target)
			return start + 1;
		else if (nums[start] > target)
			return start;
		else
			return start;

	}
};

int main() {
	Solution solution;
	vector<int> nums({ 1, 3, 5, 6 });
	vector<int> target({ 5, 2, 7, 0 });
	for (int i = 0; i < target.size(); ++i) {
		cout << solution.searchInsert(nums, target[i]) << endl;
	}
	return 0;
}