/*
 *	140. Word Break II
 *	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 *	add spaces in s to construct a sentence where each word is a valid dictionary word. 
 *	You may assume the dictionary does not contain duplicate words.

 *	Return all such possible sentences.

 *	For example, given
 *	s = "catsanddog",
 *	dict = ["cat", "cats", "and", "sand", "dog"].
 *	A solution is ["cats and dog", "cat sand dog"].
 */

/*
 *	接着139的动态规划的思路,只不过将bool型的bin改成了vector<string>,即用bin[i]来表示截止到i,有哪些分割方式
 *	但这个方法也不能通过测试样例:
 		s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
 		wordDict={"a","aa","aaa","aaaa","aaaaa","aaaaaa"}
 *	需要用139的方法先行判断这个s是否是可分的,之后再判断怎么分
 */
vector<string> wordBreak_140(string s, vector<string>& wordDict)
{
	int len(s.size());
	set<string> wordDictSet(wordDict.begin(), wordDict.end());
	vector<vector<string>> bin(len + 1, vector<string>());
	bin[0].push_back("");
	for (int i = 1;i != len + 1;++i)
	{
		for (int j = 0;j != i;++j)
		{
			if (!bin[j].empty())	//说明存在一些分割方式,相当于之前的额bin[j]=true
			{
				string substr = s.substr(j, i - j);
				if (wordDictSet.find(substr) != wordDictSet.end())
				{
					//存在新的分割方式,将它们加进来
					if (j == 0)
					{
						//若j=0,说明之前都是空的,则不需要加" "空格符
						for (string str : bin[j])
						{
							bin[i].push_back(substr);
						}
					}
					else
					{
						//需要加空格符
						for (string str : bin[j])
						{
							bin[i].push_back(str + " " + substr);
						}
					}

				}
			}
		}
	}
	return bin[len];
}