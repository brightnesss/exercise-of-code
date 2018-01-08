/*
 *	145. Binary Tree Postorder Traversal
 *	Given a binary tree, return the postorder traversal of its nodes' values.

 *	For example:
 *	Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
 *	return [3,2,1].


 *	Note: Recursive solution is trivial, could you do it iteratively?
 */

vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    if (!root) return ans;
    stack<pair<TreeNode*,bool>> bin;
    bin.push(make_pair(root,false));
    pair<TreeNode*,bool> top;
    while(!bin.empty())
    {
        top=bin.top();
        bin.pop();
        if (top.second) ans.push_back(top.first->val);
        else
        {
            top.second=true;
            bin.push(top);
            if (top.first->right) bin.push(make_pair(top.first->right,false));
            if (top.first->left) bin.push(make_pair(top.first->left,false));
        }
    }
    return ans;
}