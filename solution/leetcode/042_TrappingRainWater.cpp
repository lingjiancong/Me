#include <iostream>
#include <vector>
using std::endl;
using std::vector;
using std::cout;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0 || n == 1)
			return 0;
		int left = 0, right = 1;
		int area = 0;

		while (right < n) {
			if (height[right] < height[left]) {
				right++;
			}
			else {
				int totalArea = height[left] * (right - left);
				int partArea = 0;
				for (int i = left; i < right; ++i) {
					partArea += height[i];
				}
				area += (totalArea - partArea);

				left = right;
				right++;
			}
		}

		int leftBar = right - left;
		if (leftBar == 0 || leftBar == 1)
			return area;
		int t = left - 1;  
		left = n - 1;  right = left - 1;
		while (right > t) {
			if (height[right] < height[left]) {
				right--;
			}
			else {
				int totalArea = height[left] * (left - right);
				int partArea = 0;
				for (int i = left; i > right; --i) {
					partArea += height[i];
				}
				area += (totalArea - partArea);

				left = right;
				right--;
			}
		}

		return area;

	}
};

int main() {
	vector<int> nums({ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 });
	Solution solution;
	cout << solution.trap(nums) << endl;
	return 0;
}