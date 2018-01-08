/*
 *	113. Path Sum II
 *	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 *	For example:
 *	Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

	return	
	[
   		[5,4,11,2],
   		[5,8,4,5]
	]
 */

/*
 *	回溯法
 */

void subPathSum(TreeNode* root, const int sum, vector<vector<int>> &ans, vector<int>& tmp)
{
	tmp.push_back(root->val);
	if (root->left == NULL&&root->right == NULL)
	{
		if (sum == accumulate(tmp.begin(), tmp.end(), 0))
		{
			ans.push_back(tmp);
		}
		return;
	}
	if (root->left)
	{
		subPathSum(root->left, sum, ans, tmp);
		tmp.pop_back();
	}
	if (root->right)
	{
		subPathSum(root->right, sum, ans, tmp);
		tmp.pop_back();
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> ans;
	if (!root) return ans;
	vector<int> tmp;
	tmp.push_back(root->val);
	if (root->left == NULL&&root->right == NULL&&root->val == sum) ans.push_back(tmp);
	if (root->left) subPathSum(root->left, sum, ans, tmp);
	tmp.clear();
	tmp.push_back(root->val);
	if (root->right) subPathSum(root->right, sum, ans, tmp);
	return ans;
}