#include <iostream>
#include <vector>
#include <string>
using namespace std;

// just use to variable would be cleaner, not array
class Solution {
public:
	int numDecodings(string s) {
		if (s == "")
			return 0;
		int n = s.size();
		vector<int> d(n, 0);
		if (n == 1) {
			if (s[0] == '0')
				return 0;
			else 
				return 1;
		}
		else {
			if (s[0] == '0') {
				d[0] = 0;
				d[1] = 0;
			}
			else {
				d[0] = 1;
				if (s[1] == '0') {
					if (s[0] <= '2') {
						d[1] = 1;
					}
					else
						d[1] = 0;
				}
				else {
					int t = (s[0] - '0') * 10 + (s[1] - '0');
					if (t <= 26)
						d[1] = 2;
					else
						d[1] = 1;
				}

				for (int k = 2; k < n; ++k) {
					if (s[k - 1] == '0') {
						d[k] = 0;
					}
					else {
						int t = (s[k - 1] - '0') * 10 + (s[k] - '0');
						//cout << "t = " << t << endl;
						if (t <= 26)
							d[k] = d[k - 2];
						else
							d[k] = 0;
					}
					if (s[k] != '0')
						d[k] += d[k - 1];
				}
			}
		}
		// for (int i = 0; i < n; ++i)
		// 	cout << d[i] << " ";
		// cout << endl;
		return d[n - 1];
	}

    int numDecodings1(string s) {
        int num = 0;
        if (s == "")
        	return num;
        int k = 0;
       // cout << "s size: " << s.size() << endl;
        decode(num, s, k);
        return num;
    }
private:
	void decode(int &num, string &s, int index) {
		int n = s.size();
		//cout << "index: " << index << " n = " << n << endl;
		if (index == n) {
			num++;
			return;
		}
		else if (index > n)
			return;

		if (s[index] == '0') {
			return;
		}
		else {
			decode(num, s, index + 1);
			if (index + 1 < n) {
				int t = (s[index] - '0') * 10 + (s[index + 1] - '0');
				if (t <= 26) {
					decode(num, s, index + 2);
				}
			}
		}
	}
};

int main() {

	cout << ('1' - '0') << endl;
	Solution solution;
	//string s = "17878";
	//string s = "1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565";
	//string s = "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";
	//string s = "6068";

	string s = "100";

	cout << "s size = " << s.size() << endl;
	cout << "s = " << s << " " << solution.numDecodings1(s) << endl;
	cout << "s = " << s << " " << solution.numDecodings(s) << endl;

	return 0;
}