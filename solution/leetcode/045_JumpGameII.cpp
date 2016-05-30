#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	int jump(vector<int>& nums) {
		int size = nums.size();

		int jumpNums = 0;

		int position = 0;
		while (position < size - 1) {
			//cout << "position:" << position << endl;
			jumpNums++;

			int maxPosition = position;
			int nextPosition = position;
			int endPosition = (position + nums[position]) > size - 1 ? size - 1 : (position + nums[position]);
			for (int i = position + 1; i <= endPosition; ++i) {
				int jumpPosition = i + nums[i];
				if (i ==  size - 1 || jumpPosition >= maxPosition) {
					maxPosition = jumpPosition;
					nextPosition = i;
				}
			}
			position = nextPosition;
		}
		return jumpNums;

	}
};

int main() {
	Solution solution;
	vector<int> nums({ 2, 3, 1 });
	cout << solution.jump(nums) << endl;
	return 0;
}