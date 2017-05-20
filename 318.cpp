//leetcode No.318 Maximum Product of Word Lengths 

/*
 *	Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
 *	You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

 *	Example:
 *	Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 *	Return 16
 *	The two words can be "abcw", "xtfn".  
 */

/*
 *	先排序一下,将words按照字符串长度从大到小排序
 *	ans保存目前的最大的乘积
 *	比较每一对字符串,用一个vector保存words[i]中有哪些字符出现,对于words[j],若vector中对应的位置为true,说明words[i]与words[j]有相同的字符,可以直接舍去了
 *	优化了两处处地方:
 *	1. 若words[i]与words[j]的乘积小于ans,则不用对words[j]及之后的元素进行判断了,因为words是按降序排列,之后的元素即使没有相同字符,乘积也不会大于ans了
 *	2. 若words[i]与words[j]无相同字符,且乘积比ans大,则对ans进行更新,并且words[j]之后的元素也不用遍历了,它们的长度都不会大于words[j]
 */

int maxProduct(vector<string>& words)
{
	if (words.empty()) return 0;
	sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() > b.size();});
	int ans(0);
	int l = words.size();
	for (int i = 0;i != l - 1;++i)
	{
		vector<bool> word(26, false);
		for (int len = 0;len != words[i].size();++len) word[words[i][len] - 'a'] = true;
		for (int j = i + 1;j != l;++j)
		{
			if (words[i].size()*words[j].size() > ans)
			{
				int tmp = false;
				for (int len = 0;len != words[j].size();++len)
				{
					if (word[words[j][len] - 'a'] == true)
					{
						tmp = true;
						break;
					}
					else continue;
				}
				if (!tmp)
				{
					ans = words[i].size() * words[j].size();
					break;
				}
			}
			else break;
		}
	}
	return ans;
}

//将一个字符串当作一个26位的位向量
int maxProduct(vector<string>& words)
{
	if (words.empty()) return 0;
	int l = words.size();
	vector<int> bin(l, 0);
	for (int i = 0;i != l;++i)
	{
		//将words中的每一个元素转换为一个26位的位向量
		for (char c : words[i]) bin[i] |= c << (c - 'a');
	}
	int ans(0);

	//若两个位向量按位与为0,说明没有相同的字符
	for (int i = 0;i != l - 1;++i)
	{
		for (int j = i + 1;j != l;++j)
		{
			if (!(bin[i] & bin[j])) ans = max(ans, int(words[i].size()*words[j].size()));
		}
	}
	return ans;
}