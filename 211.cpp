/*
 *	211. Add and Search Word - Data structure design
 *	Design a data structure that supports the following two operations:
 	void addWord(word)
 	bool search(word)
 *	search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

 *	For example:
	addWord("bad")
	addWord("dad")
	addWord("mad")
	search("pad") -> false
	search("bad") -> true
	search(".ad") -> true
	search("b..") -> true

 *	Note:
	You may assume that all words are consist of lowercase letters a-z.
 */

/*
 *	插入和普通的字典树相同,主要是查询的时候"."的处理
 */
class myWordDictionary {
private:
	struct dict
	{
		bool is_string;
		vector<dict*> next;
		dict(bool b = false)
		{
			is_string = b;
			next = vector<dict*>(26, NULL);
		}
	};

	bool _search(string word, dict* cur)
	{
		dict *run = cur;
		for (int i = 0;i<word.size();++i)
		{
			if (run&&word[i] != '.') run = run->next[word[i] - 'a'];
			else if (run&&word[i] == '.')
			{
				dict *tmp = run;
				for (int j = 0;j != 26;++j)	//遇到".",就遍历搜索一遍
				{
					run = tmp->next[j];
					if (_search(word.substr(i + 1), run)) return true;
				}
			}
			else break;
		}
		return run&&run->is_string;
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
		return _search(word, root);
	}
};

//在上个版本中的_search是基本来自与leetcode discuss
//如果要我自己写,我的想法是
bool _search(string word, dict* cur)
{
	if (cur == NULL) return false;
	for (int i = 0;i<word.size();++i)
	{
		if (word[i] != '.')
		{
			if (cur->next[word[i] - 'a'] == NULL) return false;
			else cur = cur->next[word[i] - 'a'];
		}
		else
		{
			dict* tmp = cur;
			for (int j = 0;j != 26;++j)
			{
				cur = tmp->next[j];
				if (_search(word.substr(i + 1), cur)) return true;
			}
			return false;	//遍历结束还没有返回,说明不存在
		}
	}
	return cur&&cur->is_string;
}