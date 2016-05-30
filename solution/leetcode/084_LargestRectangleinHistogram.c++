#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	stack<int> heightStack, startStack;
    	int max = -1, n = heights.size();

    	if (n == 0)
    		return 0;

    	// initial stack
    	heightStack.push(heights[0]);
    	startStack.push(0);

    	// iterate heights
    	for (int i = 1; i < n; ++i) {
    		int top = heightStack.top();
    		if (heights[i] >= top) {
    			heightStack.push(heights[i]);
    			startStack.push(i);
    		}
    		else {
    			int startStackTop = i;		
    			while (!startStack.empty() && heightStack.top() > heights[i]) {
    				top = heightStack.top();
    				startStackTop = startStack.top();
    				int area = (i - startStackTop) * top;
    				if (max < area)
    					max = area;
    				startStack.pop();
    				heightStack.pop();
    			}
    			heightStack.push(heights[i]);
    			startStack.push(startStackTop);
    		}
    	}

    	// left 
    	while (!heightStack.empty()) {
    		int area = (n - startStack.top()) * heightStack.top();
    		if (area > max) 
    			max = area;
    		startStack.pop();
    		heightStack.pop();
    	}
    	return max;
    }
};

int main() {
	Solution solution;
	vector<int> nums({ 2, 1, 2});
	cout << solution.largestRectangleArea(nums) << endl;
	return 0;
}