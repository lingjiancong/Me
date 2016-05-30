#include <iostream>
using std::endl;
using std::cout;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		else if (n == INT_MIN)
			return 1/x * myPow(x, ++n);
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		return n % 2 ? x*myPow(x*x, n / 2) : myPow(x*x, n / 2);

	}
};

int main() {
	cout << (-0.0 == +0.0) << endl;
	return 0;
}