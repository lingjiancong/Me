#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// ¸ÄÐ´Îª while Ñ­»·¡£¡£¡£
class Solution {
public:
	int search(vector<int> &nums, int target) {
		return rotateBinarySearch(nums, target, 0, nums.size() -  1);
	}

	int normalBinarySearch(vector<int> &nums, int target, int first, int last) {
		if (first > last)
			return -1;
		int mid = (first + last) / 2;
		if (target > nums[mid])
			return normalBinarySearch(nums, target, mid + 1, last);
		else if (target < nums[mid])
			return normalBinarySearch(nums, target, first, mid - 1);
		else
			return mid;
	}

	int rotateBinarySearch(vector<int> &nums, int target, int first, int last) {
		if (nums[first] < nums[last])
			return normalBinarySearch(nums, target, first, last);
		int mid = (first + last) / 2;
		if (nums[first] > nums[mid]) {
			if (target < nums[first]) {
				if (target < nums[mid])
					return rotateBinarySearch(nums, target, first, mid - 1);
				else if (target > nums[mid])
					return rotateBinarySearch(nums, target, mid + 1, last);
				else
					return mid;
			}
			else if (target > nums[first]) {
				return rotateBinarySearch(nums, target, first, mid);
			}
			else
				return first;
		}
		else if (nums[first] < nums[mid]) {
			if (target > nums[first]) {
				if (target < nums[mid])
					return rotateBinarySearch(nums, target, first, mid - 1);
				else if (target > nums[mid])
					return rotateBinarySearch(nums, target, mid + 1, last);
				else
					return mid;
			}
			else if (target < nums[first]) {
				return rotateBinarySearch(nums, target, mid, last);
			}
			else
				return first;
		}
		else if (target == nums[first])
			return first;
		else if (target == nums[last])
			return last;
		else
			return -1;
	}
};

int main() {
	Solution solution;
	vector<int> vec({3, 1});
	int target = 1;
	//for (int i = 0; i < vec.size(); i++) {
	//	int target = vec[i];
	//	cout << solution.search(vec, target) << endl;
	//}
	cout << solution.search(vec, target) << endl;
	return 0;
}