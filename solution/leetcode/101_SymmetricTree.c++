#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        	return true;
        return process(root->left, root->right);
    }

private:
	bool process(TreeNode *left, TreeNode *right) {
		if (!left && !right)
			return true;
		if (!left || !right || left->val != right->val)
			return false;

		return process(left->left, right->right) && process(left->right, right->left);
	}
};


class Solution {
public:
	bool isSymmetric(TreeNode *root) {

		if (root == NULL)
			return true;

		vector<TreeNode*> order(1, root);
		int start = 0;
		int count = 0;

		do {
			int size = order.size();
			count = 0;
			for (int i = start; i < size; ++i) {
				if (order[i]) {
					order.push_back(order[i]->left);
					order.push_back(order[i]->right);
					count += 2;
				}
			}
			
			int tStart = size, tEnd = size + count - 1;
			while (tStart < tEnd) {
				int tCount = 0;
				if (order[tStart])
					tCount++;
				if (order[tEnd])
					tCount++;
				//cout << "tCount " << tCount << endl;
				if ( tCount == 1 || (tCount == 2 && order[tStart]->val != order[tEnd]->val) )
					return false;
				tStart++; tEnd--;
			}
			start = size;
			//cout << "count " << count << endl;
		} while (count != 0);

		return true;
	}
};

int main() {

	TreeNode root(1);
	TreeNode n1(2), n2(2), n3(4), n4(4);

	root.left = &n1;
	root.right = &n2;
	n1.right = &n3;
	n2.right = &n4;

	Solution solution;
	cout << solution.isSymmetric(&root) << endl;

	return 0;
}