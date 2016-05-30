#include <vector>
using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		if (n == 0)
			return vector<int>();

		vector<int> result(digits);

		for (int i = n - 1; i >= 0; --i) {
			if (result[i] == 9) {
				result[i] = 0;
			}
			else {
				result[i]++;
				return result;
			}
		}
		result[0] = 1;
		result.push_back(0);
		return result;
	}
};