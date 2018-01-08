/*
 *	139. Word Break
 *	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 *	determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
 *	You may assume the dictionary does not contain duplicate words.

 *	For example, given
 *	s = "leetcode",
 *	dict = ["leet", "code"].
 *	Return true because "leetcode" can be segmented as "leet code".
 *	题目的意思应该是一个词可以多次使用
 */

//本来是想和"word ladder的题一样,采用广度优先搜索",但超时
bool find(string s, string substr, size_t begin)
{
	//s能不能在开头的位置找到substr,begin是开始搜索的起始位置
	size_t len(substr.size());
	if (begin + len > s.size()) return false;	//若从begin开始,substr比s还长,那肯定找不到substr
	for (size_t i = 0;i < len;++i)
	{
		//遍历
		if (s[i + begin] == substr[i]) continue;
		else return false;
	}
	return true;
}

bool wordBreak(string s, vector<string>& wordDict)
{
	queue<size_t> q;	//使用q来存储目前得到的子字符串的结尾位置
	sort(wordDict.begin(), wordDict.end(), [](string a, string b) {return a.size() > b.size();});	//按照顺序长度排序,是想采用贪心的思想,先尽可能的找那些长的子串
	size_t end(0), len(s.size());
	q.push(end);	//刚开始,得到的是空子字符串,所以结尾位置为0
	while (!q.empty())
	{
		int num = q.size();
		for (int i = 0;i != num;++i)
		{
			end = q.front();
			q.pop();
			if (end == s.size()) return true;	//若结尾位置刚好就是s的结尾,那说明存在这样的分割方式
			for (string str : wordDict)
			{
				//因为可以重复利用wordDict中的字符串,所以要全部遍历
				if (find(s, str, end))
				{
					//若存在这样一种分割方式,则将新的子字符串末尾位置压入q中
					q.push(end + str.size());
				}
			}
		}
	}
	return false;
}

/*
 *	改进的广度优先搜索,可以顺利通过
 *	上面的方法不能通过的原因是存在这样的测试样例

	s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
	wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa"}

*	若采用上面的方法,因为需要不断搜索a,aa,aaa这些短的substr,所以会超时
*	改进的方法,我们采用一个set,来记录已经到达的子字符串的结尾位置,所之后还有子字符串是到达这个位置,则可以直接跳过,因为我们之前已经到达了
*	思路就是,若对于一个位置index,s[0...index)已经是可以组成的了,不管是如何组成,但一定是可以的,之后若还有其他组合可以到达index,也没有意义了,只需要从index开始向后判断即可
*/

//find函数没有改动
bool wordBreak(string s, vector<string>& wordDict)
{
	queue<size_t> q;
	sort(wordDict.begin(), wordDict.end(), [](string a, string b) {return a.size() > b.size();});
	set<size_t> visited;	//加入了visited来记录已经到达的位置
	size_t end(0), len(s.size());
	q.push(end);
	while (!q.empty())
	{
		int num = q.size();
		for (int i = 0;i != num;++i)
		{
			end = q.front();
			q.pop();
			if (visited.find(end) != visited.end()) break;	//end已经到达了,直接break,进行下一个位置的搜索
			visited.insert(end);	//若end没有到达,将end插入set
			if (end == s.size()) return true;
			for (string str : wordDict)
			{
				if (find(s, str, end))
				{
					q.push(end + str.size());
				}
			}
		}
	}
	return false;
}

/*
 *	若使用动态规划,思路也很清晰
 *	采用一个bin[i]来表示截至到第i位,这个子字符串能否可以被组成
 *	若已知bin[0]...bin[i],则bin[i+1]的更新如下:
 		令j=0...i,若bin[j]=false
 					继续遍历
 				  否则
 				  	若s[j...i+1]在wordDict中,则说明可以达到i+1
 				  	break
 */

bool wordBreak_139_v2(string s, vector<string>& wordDict)
{
	int len(s.size());
	set<string> wordDictSet(wordDict.begin(), wordDict.end());
	vector<bool> bin(len + 1, false);
	bin[0] = true;
	for (int i = 1;i != len + 1;++i)
	{
		for (int j = 0;j != i;++j)
		{
			if (bin[j])
			{
				string substr = s.substr(j, i - j);
				if (wordDictSet.find(substr) != wordDictSet.end())
				{
					bin[i] = true;
					break;
				}
			}
		}
	}
	return bin[len];
}