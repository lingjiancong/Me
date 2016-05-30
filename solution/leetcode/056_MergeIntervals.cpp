#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::vector;
using std::string;
using std::endl;
using std::cout;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
	string toString() {
		return "[" + std::to_string(start) + ", " + std::to_string(end) + "]";
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
			return a.start < b.start; 
		});
		vector<Interval> result;
		int n = intervals.size();
		if (n == 0)
			return intervals;
		int curStart = intervals[0].start, curEnd = intervals[0].end;
		for (int i = 1; i < n; ++i) {
			if (intervals[i].start > curEnd) {
				result.push_back(Interval(curStart, curEnd));
				curStart = intervals[i].start;
				curEnd = intervals[i].end;
			}
			else {
				if (intervals[i].end > curEnd)
					curEnd = intervals[i].end;
			}
		}
		result.push_back(Interval(curStart, curEnd));
		return result;
	}
};

int main() {
	vector<Interval> intervals;

	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(2, 6));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(15, 18));
	//intervals.push_back(Interval(3, 7));

	std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
		return a.start < b.start; });
	for (int i = 0; i < intervals.size(); ++i) {
		cout << intervals[i].toString() << "  ";
	}
	cout << endl;

	Solution solution;
	vector<Interval> result = solution.merge(intervals);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i].toString() << "  ";
	}
	cout << endl;

	return 0;
}