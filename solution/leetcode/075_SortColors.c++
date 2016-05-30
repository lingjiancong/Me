#include <iostream>
#include <vector>

using namespace std;


// 0, 1, 2 red, white, blue
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int reds = 0, whites = 0, blues = 0;

    	int n = nums.size();
    	for (int i = 0; i < n; ++i) {
    		if (nums[i] == 0)
    			reds++;
    		else if (nums[i] == 1)
    			whites++;
    		else if (nums[i] == 2)
    			blues++;
    	}

    	int index = 0;
    	while (index < n) {
    		if (index < reds) {
    			nums[index] = 0;
    		}
    		else if (index < reds + whites) {
    			nums[index] = 1;
    		}
    		else 
    			nums[index] = 2;
    		index++;
    	}
    }
};

int main() {

	vector<int> v({0, 1, 2, 0, 1, 2, 1});

	Solution solution;
	solution.sortColors(v);
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}