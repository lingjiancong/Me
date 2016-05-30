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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int size = intervals.size();
		if (size == 0)
			return vector<Interval>(1, newInterval);
		vector<Interval> result;
		int curStart = intervals[0].start, curEnd = intervals[0].end;
		bool inserted = false;

		if (newInterval.start < curStart) {
			inserted = true;
			curStart = newInterval.start;
			curEnd = newInterval.end;
		}

		for (int i = 0; i < size; ++i) {
			if (!inserted && newInterval.start < intervals[i].start) {
				if (newInterval.start > curEnd) {
					result.push_back(Interval(curStart, curEnd));
					curStart = newInterval.start;
					curEnd = newInterval.end;
				}
				else {
					if (newInterval.end > curEnd)
						curEnd = newInterval.end;
				}
				inserted = true;
			}
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

		if (!inserted) {
			if (newInterval.start > curEnd) {
				result.push_back(Interval(curStart, curEnd));
				curStart = newInterval.start;
				curEnd = newInterval.end;
			}
			else {
				if (newInterval.end > curEnd)
					curEnd = newInterval.end;
			}
			inserted = true;
		}
		result.push_back(Interval(curStart, curEnd));
		return result;
	}
};

int main() {
	vector<Interval> intervals;

	intervals.push_back(Interval(1, 5));
	//intervals.push_back(Interval(2, 7));
	
	Interval newInterval(2, 7);

	Solution solution;
	vector<Interval> result = solution.insert(intervals, newInterval);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i].toString() << "  ";
	}
	cout << endl;
	return 0;
}