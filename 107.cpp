//leetcode No.107 Binary Tree Level Order Traversal II 

/*
 *	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 */

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	stack<vector<int>> bin; //通过栈实现反序
	int preNum(0), curNum(0); //preNum标识上一层有多少结点，curNum表示这一层的结点数
	queue<TreeNode*> BFS; //采用广度优先遍历
	TreeNode* tmp = NULL;
	vector<int> layer; //暂时存储上一层的结点数据
	if (root)
	{
		BFS.push(root);
		preNum = 1;
	}
	while (!BFS.empty())
	{
		for (;preNum != 0;--preNum) //将上一层的结点逐个存进vector中后压入栈中
		{
			tmp = BFS.front();
			layer.push_back(tmp->val);
			BFS.pop();
			if (tmp->left)
			{
				++curNum;
				BFS.push(tmp->left);
			}
			if (tmp->right)
			{
				++curNum;
				BFS.push(tmp->right);
			}
		}
		preNum = curNum; //更新
		curNum = 0;
		bin.push(layer);
		layer.clear();
	}

	vector<vector<int>> ans;
	while (!bin.empty())
	{
		ans.push_back(bin.top());
		bin.pop();
	}
	return ans;
}

/*
 *	翻转自顶向下就好了
 */

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
	vector<vector<int>> ans;
	vector<int> layer;
	if (!root) return ans;
	queue<TreeNode*> bin;
	bin.push(root);
	int cur(1);
	TreeNode* front;
	while (!bin.empty())
	{
		cur=bin.size();
		layer.clear();
		for (int i = 0;i != cur;++i)
		{
			front = bin.front();
			bin.pop();
			layer.push_back(front->val);
			if (front->left)
			{
				bin.push(front->left);
			}
			if (front->right)
			{
				bin.push(front->right);
			}
		}
		ans.push_back(layer);
	}

	reverse(ans.begin(),ans.end());
	return ans;
}