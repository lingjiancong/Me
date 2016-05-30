#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	string getPermutation(int n, int k) {
		string kth(n, '0');
		int interval = factorial(n);
		vector<bool> v(n, false);

		int count = 0;
		while (k > 0 && count < n) {
			interval /= (n - count);
			int index = (k + interval - 1) / interval;
			k = k % interval;
			if (k == 0)
				k = interval;
			kth[count++] = '0' + get(v, index);
		}
		return kth;
	}

	int get(vector<bool> &v, int index) {
		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] == false) {
				count++;
				if (count == index) {
					v[i] = true;
					return i + 1;
				}
					
			}
		}
		return count;
	}

	int factorial(int n) {
		int result = 1;
		while (n > 0) {
			result *= n;
			--n;
		}
		return result;
	}
};

int main() {
	Solution solution;
	cout << solution.getPermutation(3, 4) << endl;
	cout << solution.getPermutation(3, 6) << endl;
	return 0;
}