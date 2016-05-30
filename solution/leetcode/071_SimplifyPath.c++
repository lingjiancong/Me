#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//did not see the condition absolute path, wrong
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string sPath;

        if (n == 0)
        	return "";
        int index = 0;
        bool isRoot = false;
        if (path[0] == '/') {
        	sPath = "/";
        	index++;
        	isRoot = true;
        }

        vector<string> sp = split(path, '/', index, isRoot);
        int i = 0, size = sp.size();
        for (; i < size - 1; ++i) {
        	sPath += sp[i];
        	sPath += "/";
        }
        if (size - 1 >= 0)
        	sPath += sp[size - 1];
        return sPath;
    }

    string simplifyPath1(string path) {
    	string res, tmp;
    	vector<string> stk;
    	stringstream ss(path);
    	while(getline(ss,tmp,'/')) {
        	if (tmp == "" || tmp == ".") continue;
        	if (tmp == ".." && !stk.empty()) stk.pop_back();
        	else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}

private:
	vector<string> split(string s, char c, int index, bool isRoot) {

		int begin = index, end = index;
		vector<string> result;
		int n = s.size(), len = 0;

		while (++end <= n) {
			if (end >= n || s[end] == c) {
				string p(s, begin, end - begin);

				if (p.size() == 1 && p[0] == c)
					;
				else if (p == ".")
					;	
				else if (p == ".." && len != 0 && result[len - 1] != "..") {
						len--;
				}
				else if (p == ".." && isRoot)
					;
				else {
					int pSize = result.size();
					if (len > pSize - 1)
						result.push_back(p);
					else
						result[len] = p;
					len++;
				}
				begin = end + 1;
				while (begin < n && s[begin] == c)
					++begin;
				end = begin;
			}
		}

		return vector<string>(result.begin(), result.begin() + len);
	}
};

int main() {
	Solution solution;
	string path = "/home/";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "/a/./b/../../c/";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "a/../../ab/";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "a/./b/ab/.././a";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "///";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "/..";
	cout << path << " == " << solution.simplifyPath(path) << endl;

	path = "/home//foo/";
	cout << path << " == " << solution.simplifyPath(path) << endl;
	return 0;
}