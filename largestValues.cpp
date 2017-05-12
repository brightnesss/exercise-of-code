//leetcode No.515 Find Largest Value in Each Tree Row 

/*
 *	You need to find the largest value in each row of a binary tree.
 *	Example:
 *	Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

 *	Output: [1, 3, 9]
 */

vector<int> largestValues(TreeNode* root)
{
	vector<int> row, ans;
	queue<pair<TreeNode*,bool>> bin;
	if (!root) return ans;
	bin.push(make_pair(root,false));
	pair<TreeNode*, bool > tmp;
	while (!bin.empty())
	{
		//第一遍只将该层的数push进row数组,第二遍才将front的左右子树push进队列
		tmp = bin.front();
		if (tmp.second)
		{
			if (!row.empty())
			{
				int num = *max_element(row.begin(), row.end());
				ans.push_back(num);
				row.clear();
			}
			if (tmp.first->left) bin.push(make_pair(tmp.first->left, false));
			if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
			bin.pop();
		}
		else
		{
			int num = tmp.first->val;
			row.push_back(num);
			bin.pop();
			bin.push(make_pair(tmp.first, true));
		}
	}
	return ans;
}