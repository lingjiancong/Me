#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::endl;
using std::cout;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int n = words.size();
		vector<string> result;
		if (n == 0)
			return result;

		int range0 = 0, range1 = 0;
		int count = 0;

		for (int i = 0; i < n; ++i) {
			count += words[i].size() + 1;
			if (count - 1 > maxWidth) {
				result.push_back(generateLine(words, range0, range1 - 1, maxWidth));
				range0 = i; range1 = i + 1;
				count = words[i].size() + 1;
			}
			else {
				range1++;
			}
		}
		result.push_back(generateLastLine(words, range0, range1 - 1, maxWidth));
		return result;
	}

private:
	string generateLastLine(vector<string> &words, int range0, int range1, int maxWidth) {
		string line(maxWidth, ' ');

		int index = 0;
		while (range0 <= range1) {
			for (int i = 0; i < words[range0].size(); ++i) {
				line[index++] = words[range0][i];
			}
			index++;
			range0++;
		}
		return line;
	}

	string generateLine(vector<string> &words, int range0, int range1, int maxWidth) {
		int gap = range1 - range0;
		int len = 0;
		for (int i = range0; i <= range1; ++i)
			len += words[i].size();

		int leftSpace = maxWidth - len;
		int baseSpaceLen = gap == 0 ? 0 : leftSpace / gap;
		int addOneSpaceLen = gap == 0 ? 0 : leftSpace % gap;

		string line(maxWidth, ' ');
		int index = 0;
		int begin = range0;
		while (begin < range1) {
			for (int i = 0; i < words[begin].size(); ++i) {
				line[index++] = words[begin][i];
			}
			if (begin - range0 < addOneSpaceLen)
				index += (baseSpaceLen + 1);
			else
				index += baseSpaceLen;
			begin++;
		}
		for (int i = 0; i < words[begin].size(); ++i) {
			line[index++] = words[begin][i];
		}
		return line;
	}
};

int main() {

	vector<string> words({ "Here", "is", "an", "example", "of", "text", "justification."});
	Solution solution;

	int maxWidth = 14;
	vector<string> justification = solution.fullJustify(words, maxWidth);

	for (int i = 0; i < justification.size(); ++i) {
		cout << "\"" << justification[i] << "\"" << endl;
	}

	return 0;
}