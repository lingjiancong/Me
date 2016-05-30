#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n;
        for (int i = m + n - 1; i >= n; --i) {
        	nums1[i] = nums1[i - n];
        }
        int p1 = n, p2 = 0, p = 0;
        while (p1 < total && p2 < n) {
        	if (nums1[p1] < nums2[p2]) {
        		nums1[p++] = nums1[p1++];
        	}
        	else {
        		nums1[p++] = nums2[p2++];
        	}
        }
        while (p1 < total) {
        	nums1[p++] = nums1[p1++];
        }
        while (p2 < n) {
        	nums1[p++] = nums2[p2++];
        }
    }
};

int main() {
	vector<int> nums1({0, 0, 0, 0, 0});
	vector<int> nums2({2, 8, 12, 12, 12});

	int m = 0, n = 5;
	Solution solution;
	solution.merge(nums1, m, nums2, n);
	cout << " -- ";
	for (int i = 0; i < m + n; ++i)
		cout << nums1[i] << " -- ";
	cout << endl;

	return 0;
}