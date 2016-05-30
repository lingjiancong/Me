#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		for (int i = 0, j = height.size() - 1; i < j;) {
			if (height[i] <= height[j]) {
				int multi = (j - i) * height[i];
				res = res > multi ? res : multi;
				i++;
			}
			else {
				int multi = (j - i) * height[j];
				res = res > multi ? res : multi;
				j--;
			}
		}
		return res;
	}
};