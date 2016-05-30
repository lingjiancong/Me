#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = leftBinarySearch(nums, target);
		int end = rightBinarySearch(nums, target);
		vector<int> result({ start, end });
		return result;
	}

	int leftBinarySearch(vector<int> &nums, int target) {
		int start = 0, end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = (start + end) / 2;
			if (target <= nums[mid])
				end = mid;
			else
				start = mid + 1;
		}
		if (nums[start] == target)
			return start;
		if (nums[end] == target)
			return end;
		return -1;
	}

	int rightBinarySearch(vector<int> &nums, int target) {
		int start = 0, end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = (start + end) / 2;
			if (target >= nums[mid])
				start = mid;
			else
				end = mid - 1;
		}
		if (nums[end] == target)
			return end;
		if (nums[start] == target)
			return start;
		return -1;
	}
};

int main() {
	vector<int> nums({5, 1, 1, 8, 8, 8, 10});
	Solution solution;
	int target = 8;
	vector<int> result = solution.searchRange(nums, target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}