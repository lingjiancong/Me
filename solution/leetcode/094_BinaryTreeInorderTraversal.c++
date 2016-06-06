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
    	stack<TreeNode*> tree;
    	stack<int> flag;

    	vector<int> inorder;
    	if (!root)
    		return inorder;

    	// initial
    	tree.push(root);  flag.push(0);

    	while (!tree.empty()) {
    		TreeNode *t = tree.top();
    		int f = flag.top();

    		switch(f) {
    			case 0:
    				while (t->left) {
    					t = t->left;
    					tree.push(t);
    					flag.push(0);
    				}
    				flag.pop(); flag.push(1);
    			case 1:
    				inorder.push_back(t->val);
    				if (t->right) {
    					tree.pop(); flag.pop();
    					tree.push(t->right); flag.push(0);
    				}
    				else {
    					tree.pop(); flag.pop();
    					if (!tree.empty()) {
    						flag.pop(); flag.push(1);
    					}
    				}
    		}
    	}

    	return inorder;
        
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