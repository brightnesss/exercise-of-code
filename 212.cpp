/*
 *	212. Word Search II
 *	Given a 2D board and a list of words from the dictionary, find all words in the board.
 *	Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
 	The same letter cell may not be used more than once in a word.

 *	For example,
	Given words = ["oath","pea","eat","rain"] and board =
	[
  	 ['o','a','a','n'],
  	 ['e','t','a','e'],
  	 ['i','h','k','r'],
  	 ['i','f','l','v']
	]
	Return ["eat","oath"].

 *	Note:
	You may assume that all inputs are consist of lowercase letters a-z.
 */

/*
 *	使用字典树来进行存储和搜索
 */

struct dict 	//字典树数据结构
{
	bool is_string;
	vector<dict*> next;
	dict(bool b = false)
	{
		is_string = b;
		next = vector<dict*>(26, NULL);
	}
};

//字典树实现类
class myWordDictionary {
private:
	dict* _search(string word)
	{
		dict *tmp = root;
		for (int i = 0;i != word.size();++i)
		{
			if (tmp->next[word[i] - 'a'] == NULL) return NULL;
			tmp = tmp->next[word[i] - 'a'];
		}
		return tmp;
	}

	dict* root;

public:
	/** Initialize your data structure here. */
	myWordDictionary() {
		root = new dict();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		dict *tmp = root;
		for (int i = 0;i != word.size();++i)
		{
			if (tmp->next[word[i] - 'a'] == NULL) tmp->next[word[i] - 'a'] = new dict();
			tmp = tmp->next[word[i] - 'a'];
		}
		tmp->is_string = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		dict *ans = _search(word);
		if (!ans) return false;
		else return ans->is_string;
	}

	dict* startwith(string word)
	{
		return _search(word);
	}
};

/*
 *	搜索实现函数
 *	1)首先先将board当前位置的字符加入目前的答案ansstr中
	2)在字典中搜索是否有以ansstr开头的字符串
		若没有,则返回,进行下一次搜索
		若有:1.ansstr是否是一个完整的字符串,若是,则需要加入答案ans中
			 2.将board当前字符变为'.',用来标记这个位置已经用过了,之后别再用
			 3.深度优先遍历其余位置
			 4.这个位置全部便利结束后,需要将当前位置的'.'在改回来
 */
void subFindWords(vector<vector<char>> &board, set<string> &ans, myWordDictionary &prim, string ansstr, const int m, const int n, int i, int j)
{
	ansstr += board[i][j];
	dict *tmp = prim.startwith(ansstr);
	if (!tmp) return;
	else
	{
		if (tmp->is_string) ans.insert(ansstr);
		char c(board[i][j]);
		board[i][j] = '.';
		if (i + 1 < m&&board[i + 1][j] != '.') subFindWords(board, ans, prim, ansstr, m, n, i + 1, j);
		if (i - 1 >= 0 && board[i - 1][j] != '.') subFindWords(board, ans, prim,ansstr, m, n, i - 1, j);
		if (j + 1 < n&&board[i][j + 1] != '.') subFindWords(board, ans, prim, ansstr, m, n, i, j + 1);
		if (j - 1 >= 0 && board[i][j - 1] != '.') subFindWords(board, ans, prim, ansstr, m, n, i, j - 1);
		board[i][j] = c;
	}
}

/*
 *	主调函数
 *	先实现一个字典树,将words中的所有string存储入字典树中
 *	然后以board中的任一个字符为起始字符,开始遍历搜索
 */
vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	myWordDictionary prim;
	for (string s : words) prim.addWord(s);
	int m(board.size()), n(board[0].size());
	set<string> anstmp;
	for (int i = 0;i != m;++i)
	{
		for (int j = 0;j != n;++j)
		{
			subFindWords(board, anstmp, prim, "", m, n, i, j);
		}
	}
	vector<string> ans;
	for (string s : anstmp) ans.push_back(s);
	return ans;
}