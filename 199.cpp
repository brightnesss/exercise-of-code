//leetcode No.199 Binary Tree Right Side View

/*
 *	Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 *	For example:
 *	Given the following binary tree,

   		1            <---
 	  /   \
	 2     3         <---
 	  \     \
  	   5     4       <---

 *	You should return [1, 3, 4].
 */

//把每一层所有的值都记下来,并返回最后一个值(最后一个值是这一层最右边的值)
vector<int> rightSideView(TreeNode* root)
{

	if (!root) return vector<int>();
	vector<int> ans;
	queue<pair<TreeNode*,bool>> bin;
	ans.push_back(root->val);
	bin.push(make_pair(root, false));
	vector<int> layer;
	pair<TreeNode*, bool> tmp;
	while (!bin.empty())
	{
		tmp = bin.front();
		if (!tmp.second)
		{
			bin.pop();
			if (tmp.first->left) layer.push_back(tmp.first->left->val);
			if (tmp.first->right) layer.push_back(tmp.first->right->val);
			bin.push(make_pair(tmp.first, true));
		}
		else
		{
			if (!layer.empty()) ans.push_back(layer.back());
			layer.clear();
			bin.pop();
			if (tmp.first->left) bin.push(make_pair(tmp.first->left, false));
			if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
		}
	}
	return ans;
}
//优化一下以上的写法
vector<int> rightSideView(TreeNode* root)
{
	if (!root) return vector<int>{};
	vector<int> ans, layer;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode *front;
	int len;
	while (!q.empty())
	{
		len = q.size();
		layer.clear();
		for (int i = 0;i != len;++i)
		{
			front = q.front();
			q.pop();
			layer.push_back(front->val);
			if (front->left) q.push(front->left);
			if (front->right) q.push(front->right);
		}
		ans.push_back(layer.back());
	}
	return ans;
}


/*
 *	maybe a better way
 *	采用类似先序遍历的方法,每次先遍历右孩子
 *	用一个level层数来指示该节点是否为最右边的结点
 *	当最右支的结点遍历完毕,进行回溯时,就通过level的值来控制不会使同一层的结点进入
 */
void preorder(TreeNode* root, int level, vector<int> &ans)
{
	if (!root) return;
	if (level > ans.size()) ans.push_back(root->val);
	preorder(root->right, level + 1, ans);
	preorder(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode* root)
{
	vector<int> ans;
	preorder(root, 1, ans);
	return ans;
}
