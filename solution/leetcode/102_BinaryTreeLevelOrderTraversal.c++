class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

    	vector<vector<int>> result;
    	if (!root)
    		return result;
    	vector<TreeNode*> nodes(1, root);
    	specificLevel(result, nodes);

    	return result;        
    }

private:
	void specificLevel(vector<vector<int>> &result, vector<TreeNode*> nodes) {
		int n = nodes.size();

		if (n == 0)
			return;

		vector<TreeNode*> nexts;
		vector<int> levelInts;

		for (int i = 0; i < n; ++i) {
			levelInts.push_back(nodes[i]->val);
			if (nodes[i]->left)
				nexts.push_back(nodes[i]->left);
			if (nodes[i]->right)
				nexts.push_back(nodes[i]->right);
		}

		result.push_back(levelInts);
		specificLevel(result, nexts);
	}
};

class Solution {
	vector<vector<int>> ret;
	
public:
	void buildVector(TreeNode *root, int depth)	{
		if(root == NULL) return;
        if(ret.size() == depth)
        	ret.push_back(vector<int>());

        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
    	buildVector(root, 0);
    	return ret;
    }
};