/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return right + 1;
        if (right == 0)
            return left + 1;

        int min = left > right ? right : left;
        return min + 1;
    }
};

int main() {
    return 0;
}
