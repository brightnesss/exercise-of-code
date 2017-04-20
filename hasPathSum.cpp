// leetcode No.112 Path Sum

/*
 *	Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. 
 *	For example:
 *	Given the below binary tree and sum = 22, 
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 *	return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

//必须是一条从根到叶子的路径
//如果一个结点不是叶子结点，就必须继续向下搜索

bool hasPathSum(TreeNode* root, int sum)
{
	int count(0);
	stack<pair<TreeNode*,bool>> bin;
	if (root) bin.push(make_pair(root,false));
	else return false;
	pair<TreeNode*, bool> tmp;	//需要一个记号表示是向下访问还是向上回溯
	while (!bin.empty())
	{
		tmp = bin.top();
		if (tmp.second == true)	//如果是回溯的，则要将该结点的值删掉并从栈中弹出
		{
			count -= tmp.first->val;
			bin.pop();
		}
		else
		{
			//如果是向下搜索，首先将值加上，然后继续搜索其子结点
			count += tmp.first->val;
			tmp.second = true;
			bin.pop();
			bin.push(tmp);
			if (count == sum && tmp.first->left == NULL && tmp.first->right == NULL) return true; //如果是叶子结点并值相等，返回
			else
			{
				//否则继续向下直到叶子结点
				if (tmp.first->left) bin.push(make_pair(tmp.first->left, false)); //每一个结点入栈时标记都是false，表示向下搜索
				if (tmp.first->right) bin.push(make_pair(tmp.first->right, false));
			}
		}
	}
	return false;
}