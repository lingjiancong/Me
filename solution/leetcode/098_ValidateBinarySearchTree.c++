#include <iostream>
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
    bool isValidBST1(TreeNode* root) {
    	if (root == NULL)
    		return true;

    	vector<int> result;
    	traversal(root, result);

    	int n = result.size();
    	for (int i = 0; i < n - 1; ++i) {
    		if (result[i] >= result[i + 1])
    			return false;
    	}
    	return true;
    }

    void traversal(TreeNode *node, vector<int> &result) {
    	if (node == NULL)
    		return;
    	traversal(node->left, result);
    	result.push_back(node->val);
    	traversal(node->right, result);
    }

    bool isValidBST(TreeNode* root) {
    	if (root == NULL)
    		return true;
    	return traversalLeft(root->left, root->val) && traversalRight(root->right, root->val);
    }

    bool traversalLeft(TreeNode *node, int high) {
    	if (node == NULL)
    		return true;
    	if (node->val >= high)
    		return false;
    	return traversalLeft(node->left, node->val) && traversalLeftRight(node->right, node->val, high);
    }

    bool traversalRight(TreeNode *node, int low) {
    	if (node == NULL)
    		return true;
    	if (node->val <= low)
    		return false;
    	return traversalRight(node->right, node->val) && traversalLeftRight(node->left, low, node->val);
    }

    bool traversalLeftRight(TreeNode *node, int low, int high) {
    	if (node == NULL)
    		return true;
    	if (node->val <= low || node->val >= high)
    		return false;
    	return traversalLeftRight(node->left, low, node->val) && traversalLeftRight(node->right, node->val, high);
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

	cout << solution.isValidBST(&root) << endl;


	return 0;
}