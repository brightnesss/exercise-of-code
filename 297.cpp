/*
 *	297. Serialize and Deserialize Binary Tree
 *	Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
 *	or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

 *	Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
 *	You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

 *	For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5

 *	as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, 
 *	so please be creative and come up with different approaches yourself.
 *	Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

// Encodes a tree to a single string.

/*
 *	广度优先搜索遍历root,将每一个值转换为string后存入一个数组vec中
 *	因为将null也存入了数组,但所有最后的null是不应该出现的,所以在后面遍历一下vec,若vec的末尾为null,则删掉
 *	再将vec中的string存入ans中
 */
string serialize(TreeNode* root) 
{
    vector<string> vec;
    if (!root) return string("[]");
    queue<TreeNode*> bin;
    bin.push(root);
    TreeNode *front;
    while(!bin.empty())
    {
        front=bin.front();
        bin.pop();
        if (front==NULL)
        {
            vec.push_back("null");
            continue;
        }
        vec.push_back(to_string(front->val));
        bin.push(front->left);
        bin.push(front->right);
    }
    while(true)
    {
    	//若末尾为null,则删掉
        if (vec.back()=="null") vec.pop_back();
        else break;
    }
    //将vec存入ans中
    string ans("[");
    for (int i=0;i!=vec.size();++i)
    {
        if (i==0) ans+=vec[i];
        else
        {
            ans+=",";
            ans+=vec[i];
        }
    }
    ans+="]";
    return ans;
}

/*
 *	将string解码为一颗树,同样采用BFS
 *	先要处理string,将string的"[]"都删掉,然后以","为分隔符,对string进行分割
 *	之后就建立这棵树
 */

// Decodes your encoded data to tree.

//分割算法
vector<string> SplitString(const std::string& s, const std::string& c)
{
    vector<string> v;
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
    v.push_back(s.substr(pos1));
    return v;
}



TreeNode* deserialize(string data) 
{
    if (data.size()==2) return NULL;
    data.pop_back();
    data.erase(data.begin());
    vector<string> bin=SplitString(data,",");
    TreeNode *root=new TreeNode(atoi(bin[0].c_str()));
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *front;
    int index(1),l(bin.size());
    while(!q.empty())
    {
        if (index>=l) break;	//若已经超过了这棵树的大小,退出
        int len=q.size();
        for (int i=0;i!=len;++i)
        {
            front=q.front();
            q.pop();
            if (index<l&&bin[index]!="null")
            {
                front->left=new TreeNode(atoi(bin[index].c_str()));
                q.push(front->left);
            }
            ++index;
            if (index<l&&bin[index]!="null")
            {
                front->right=new TreeNode(atoi(bin[index].c_str()));
                q.push(front->right);
            }
            ++index;
        }
    }
    return root;
}