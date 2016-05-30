#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	string ip = "";
    	vector<string> result;
    	int begin = 0, k = 4;
    	restoreIpAddress(s, result, ip, begin, k);
    	return result;
    }
private:
	void restoreIpAddress(const string &s, vector<string> &result, string ip, int begin, int k) {
		int n = s.size(), ipLargestLen = 3;
		if (k == 0 && begin == n)
			result.push_back(ip);
		if (n - begin > k * ipLargestLen || begin >= n)
			return;

		int diff = n - begin, t = 0, ipInt = 256;
		while (++t <= diff && t <= ipLargestLen) {
			string sub = s.substr(begin, t);
			if (sub[0] == '0') {
				string ipCache = ip + sub + (k == 1 ? "" : ".");
				restoreIpAddress(s, result, ipCache, begin + t, k - 1);
				break;
			}
			if (stoi(sub) < ipInt) {
				string ipCache = ip + sub + (k == 1 ? "" : ".");
				restoreIpAddress(s, result, ipCache, begin + t, k - 1);
			}
			else
				return;
		}

	}
};

int main() {
	string s = "25525511135";
	Solution solution;
	vector<string> result = solution.restoreIpAddresses(s);
	int n = result.size();

	cout << "digits: " << s << endl;
	cout << " [ " << endl;
	for (int i = 0; i < n; ++i) {
		cout << result[i] << endl;
	}
	cout << " ] " << endl;  

	s = "010010";
	cout << "digits: " << s << endl;
	result = solution.restoreIpAddresses(s);
	n = result.size();
	cout << " [ " << endl;
	for (int i = 0; i < n; ++i) {
		cout << result[i] << endl;
	}
	cout << " ] " << endl;  

	return 0;
}