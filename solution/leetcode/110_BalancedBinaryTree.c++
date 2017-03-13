/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isBalanced(TreeNode* root) {
        judge = true;
        int i = deepth(root);

        return judge;
    }

private:

    bool judge;

    int deepth(TreeNode* node) {
        if (!judge)
            return 0; 

        if (node == NULL)
            return -1;
        int left_depth = deepth(node->left);
        int right_depth = deepth(node->right);

        int max = left_depth > right_depth ? left_depth : right_depth;
        int min = left_depth > right_depth ? right_depth : left_depth;

        if (max - min > 1)
            judge = false;
        return max + 1;
    }
};

int main() {
    return 0;
}
