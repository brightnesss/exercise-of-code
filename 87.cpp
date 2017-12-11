/*
 *	87. Scramble String
 *	Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 *	Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 *	To scramble the string, we may choose any non-leaf node and swap its two children.

 *	For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
 *	We say that "rgeat" is a scrambled string of "great".

 *	Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
 *	We say that "rgtae" is a scrambled string of "great".

 *	Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

/*
 *	注意一点,即这颗二叉树的分割不一定是从string的中点开始分割的,从任意一点都可以
 *	判断两个string是否是Scramble,如果两个string本身就是相等的,那一定是Scramble,若本身不等,则可以通过该方法来使得他们相等
 */

/*
 *	递归的方法
 */

bool isScramble(string s1, string s2)
{
	if (s1 == s2) return true;	//若本身相等,就可以直接返回

	//判断两个string中是否包含不同的字符,或者(这种情况更常见)包含相同的字符不同次数
	//如果存在这两种情况,则必然不相同
	vector<int> num(26, 0);
	int len(s1.size());
	for (int i = 0;i != len;++i)
	{
		++num[s1[i] - 'a'];
		--num[s2[i] - 'a'];
	}
	for (int k : num) if (k != 0) return false;

	/*
	 *	相同的情况有两种,假设切割的位置为i
	 *	1. 不交叉,则若想相等,需要s1的前半段与s2的前半段相等,s1的后半段与s2的后半段相等
	 *	2. 交叉,则若想相等,需要s1的前半段与s2的后半段相等,s1后半段与s2的前半段相等
	 */
	for (int i = 1;i != len;++i)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;	//情况1
		if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) return true;	//情况2
	}
	return false;
}