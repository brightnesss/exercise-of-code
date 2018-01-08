/*
 *	132. Palindrome Partitioning II
 *	Given a string s, partition s such that every substring of the partition is a palindrome.
 *	Return the minimum cuts needed for a palindrome partitioning of s.

 *	For example, given s = "aab",
 *	Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

//想直接改编131的题,将返回值修改一下就好了,但结果超时
bool isPartition_131(string s)
{
	string par = s;
	reverse(par.begin(), par.end());
	return par == s;
}

void subPartition_131(const string s, int start, vector<string> &tmp, vector<vector<string>> &ans)
{
	if (start == s.size()) ans.push_back(tmp);
	for (int i = start;i < s.size();++i)
	{
		if (isPartition_131(s.substr(start, i - start + 1)))
		{
			tmp.push_back(s.substr(start, i - start + 1));
			subPartition_131(s, i + 1, tmp, ans);
			tmp.pop_back();
		}
	}
}

vector<vector<string>> partition_131(string s)
{
	vector<vector<string>> ans;
	if (s.empty()) return 0;
	int len(s.size());
	vector<string> tmp;
	subPartition_131(s, 0, tmp, ans);
	int minNum(INT_MAX);
	for (vector<string> vec:ans) minNum = min(minNum, int(vec.size())-1);
	return minNum;
}

//一个简单的动态规划,还是超时,但多过了几个样例
//用bin[i][j]来表示第i位开始,第j位结束(包含第j位)的字符串需要切割多少刀
int minCut(string s)
{
	if (s.empty()) return 0;
	int len(s.size());
	vector<vector<int>> bin(len, vector<int>(len, 0));
	int j;
	for (int num = 1;num < len;++num)
	{
		for (int i = 0;i < len;++i)
		{
			j = i + num;
			if (j >= len) break;
			if (isPartition_131(s.substr(i, j - i + 1)))	//若s[i...j]就是一个回文,则不需要切割
			{
				bin[i][j] = 0;
			}
			else
			{
				//否则,bin[i][j]最多需要切割j-i刀,即切成一个一个字母,最少需要切一刀
				//则至少需要切一刀,分别计算这一刀左边的需要多少刀,右边的需要多少刀,两者之和加上这一刀
				bin[i][j] = j - i;
				for (int z = i;z < j;++z)
				{
					bin[i][j] = min(bin[i][z] + bin[z + 1][j] + 1, bin[i][j]);
				}
			}
		}
	}
	return bin[0][len - 1];
}

/*
 *	用bin[i][j]来记录s[i...j]是不是回文字符串
 *	用ans[i]来表示s[i...len)需要切割多少次,则最终的答案是ans[0]
 *	如果bin[i][j]=true,说明bin[i][j]是回文
 		若j==len-1,则说明s[i...len)是回文,则ans[i]=0
 		若j!=len-1,则s[i...len)不是回文但s[i...j]是回文,则说明需要在j和j+1之间进行至少一次分割,则ans[i]=ans[j+1]+1
 */
int minCut_v2(string s)
{
	if (s.empty()) return 0;
	int len(s.size());
	vector<vector<bool>> bin(len, vector<bool>(len, 0));
	vector<int> ans(len, 0);
	for (int i = len - 1;i >= 0;--i)
	{
		ans[i] = len - i - 1;
		for (int j = i;j < len;++j)
		{
			if (s[i] == s[j] && (j - i < 2 || bin[i + 1][j - 1]))
			{
				bin[i][j] = true;
				if (j == len - 1) ans[i] = 0;
				else ans[i] = min(ans[i], 1 + ans[j + 1]);
			}
		}
	}
	return ans[0];
}