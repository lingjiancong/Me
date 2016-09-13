#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> nums;
        if (root == NULL)
            return nums;

        // init
        bool flag = false;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode *next = st.top();
            if (flag) {
                st.pop();
                nums.push_back(next->val);
                if (next->right != NULL) {
                    st.push(next->right);
                    flag = false;
                } else
                    flag = true;
            } else {
                if (next->left == NULL) {
                    nums.push_back(next->val);
                    st.pop();
                    if (next->right == NULL)
                        flag = true;
                    else
                        st.push(next->right);
                } else {
                    st.push(next->left);
                }

            }
        }
        return nums;
    }

	vector<int> inorderTraversalRecursive(TreeNode *root) {
		vector<int> result;
		inorderTraversalRecursiveAdd(root, result);
		return result;
	}

	void inorderTraversalRecursiveAdd(TreeNode *node, vector<int> &result) {
		if (node == NULL) 
			return;
		inorderTraversalRecursiveAdd(node->left, result);
		result.push_back(node->val);
		inorderTraversalRecursiveAdd(node->right, result);
		
	}
};

int main() {

	TreeNode root(1);
	TreeNode n1(2), n2(3), n3(4), n4(5);

	root.left = &n1;
	n1.left = &n4; 
	n1.right = &n2;
	n2.right = &n3;

	Solution solution;
	vector<int> re1 = solution.inorderTraversal(&root);
	vector<int> re2 = solution.inorderTraversalRecursive(&root);

	for (int i = 0; i < re1.size(); ++i) {
		cout << " " << re1[i];
	}
	cout << endl;

	for (int j = 0; j < re2.size(); ++j) {
		cout << " " << re2[j];
	}
	cout << endl;
	return 0;
}
