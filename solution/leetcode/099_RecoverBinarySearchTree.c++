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

private:
    TreeNode *cache;
    bool in;

    TreeNode *left;
    TreeNode *right;

public:

    void traversal(TreeNode *node, vector<int> &result) {
    	if (node == NULL)
    		return;
    	traversal(node->left, result);
    	result.push_back(node->val);
    	traversal(node->right, result);
    }

    void postorderTraversal(TreeNode *node, vector<int> &result) {
        if (node == NULL)
            return;
        postorderTraversal(node->right, result);
        result.push_back(node->val);
        postorderTraversal(node->left, result);
        
    }

    void decreaseTraversal(TreeNode *node) {
        if (node->right)
            decreaseTraversal(node->right);

        if (in && node->val > cache->val) {
            right = cache;
           return;
        }

        cache = node;
        in = true;

        if (node->left)
            decreaseTraversal(node->left);
    }

    void increaseTraversal(TreeNode *node) {
        if (node->left)
            increaseTraversal(node->left);

        if (in && node->val < cache->val) {
            left = cache;
            return;
        }

        cache = node;
        in = true;

        if (node->right)
            increaseTraversal(node->right);
    }

    void recoverTree(TreeNode *root) {
        if (root == NULL)
            return;

        left = right = NULL;

        in = false;
        increaseTraversal(root);
        in = false;
        decreaseTraversal(root);

        if (left && right) {
            int t = left->val;
            left->val = right->val;
            right->val = t;
        }
    }


    void recoverTree1(TreeNode* root) {
        if (root == NULL)
            return;
        vector<int> result;
        traversal(root, result);

        int n = result.size(), k = 0;
        const int N = 2;
        int swapValue[N];

        for (int i = 0; i < n - 1 && k < N; ++i) {
            if (result[i] > result[i + 1] && k < N) {
                swapValue[k++] = result[i];
                break;
            }
        }

        for (int i = n - 1; i > 0 && k < N; --i) {
            if (result[i] < result[i - 1] && k < N) {
                swapValue[k++] = result[i];
                break;
            }
        }

        if (k == N) {
            TreeNode *p = alter(root, swapValue[0], swapValue[1], NULL);
            alter(root, swapValue[1], swapValue[0], p);
        }
    }

    TreeNode* alter(TreeNode *node, int oldVal, int newVal, TreeNode *excludeNode) {
        if (node == NULL)
            return NULL;
        if (node->val == oldVal && (node != excludeNode || excludeNode == NULL) ) {
            node->val = newVal;
            return node;
        }
        TreeNode *p = alter(node->left, oldVal, newVal, excludeNode);
        TreeNode *q = alter(node->right, oldVal, newVal, excludeNode);
        return p == NULL ? q : p;
    }
};

void print(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << " " << array[i];
    }
    cout << endl;
}

int main() {

	TreeNode root(5);
	TreeNode n1(2), n2(3), n3(4), n4(1);

	root.left = &n1;
	n1.left = &n4; 
	n1.right = &n2;
	n2.right = &n3;

	Solution solution;

    vector<int> init;
    solution.traversal(&root, init);
    print(init);

    vector<int> init1;
    solution.postorderTraversal(&root, init1);
    print(init1);

    n1.val = 4, n3.val = 2;
    vector<int> swapArray;
    solution.traversal(&root, swapArray);
    print(swapArray);

    solution.recoverTree(&root);
    vector<int> recover;
    solution.traversal(&root, recover);
    print(recover);

	return 0;
}