#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result;
    	result.push_back(0);

    	for (int i = 0; i < n; ++i) {
    		int size = result.size();

    		for (int j = size - 1; j >= 0; --j) {
    			result.push_back(result[j] + (1 << i));
    		}
    	}

    	return result;
    }
};

int main() {
	int n = 3;
	Solution solution;
	vector<int> result = solution.grayCode(n);
	int size = result.size();
	for (int i = 0; i < size; ++i) {
		cout << result[i] << endl;
	}
	return 0;
}