/*
 *	115. Distinct Subsequences
 *	Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 *	A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters 
 *	without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 *	Here is an example:
 *	S = "rabbbit", T = "rabbit"
 *	Return 3.

 *	相当于切割一部分S,使得S==T,问有多少张不同的切割方法
 */

/*
 *	回溯,Time Limited
 *	pair<int,int>来存放ps的位置和pt,即存放相等时的状态
 *	遍历s,若s[ps]==t[pt],则将这个状态压入栈中,若不等,则ps继续后移,直到遍历结束
 *	遍历s结束后,若stmp==t,则说明这一次的切割是合法的,则++ans
 *	遍历接收后,不论是否合法,都需要恢复最新的状态,从最新的状态开始,ps=state_ps+1,pt=state_pt,即ps从保存的状态的后一位开始,pt任然不变,因为要对pt进行新的匹配
 */
int numDistinct(string s, string t)
{
	int lens(s.size()), lent(t.size());
	string stmp("");
	stack<pair<int, int>> bin;
	int begin(-1);	//begin是第一个字符,即t[0]的在s中的开始位置
	int ps(0), pt(0);
	int ans(0);
	while (begin <= lens - lent)	//若begin?lens-lent,则不可能存在s的子字符串与t相等,因为长度就不想等
	{
		if (bin.empty())
		{
			//若bin是空的,说明此时第一个字符都没有
			++begin;
			ps = begin;
			pt = 0;
			if (s[ps] == t[pt])
			{
				bin.push(make_pair(ps, pt));
				stmp += t[pt];
				++ps;
				++pt;
			}
		}
		else
		{
			while (ps < lens)
			{
				//遍历直到结束
				if (s[ps] == t[pt])
				{
					bin.push(make_pair(ps, pt));
					stmp += t[pt];
					++ps;
					++pt;
				}
				else ++ps;
			}
			//加载状态
			if (stmp == t) ++ans;
			ps = bin.top().first + 1;
			pt = bin.top().second;
			stmp.pop_back();
			bin.pop();
		}
	}
	return ans;
}

/*
 *	动态规划
 *	建立二维数组bin,bin[i][j]表示s[0...i-1]包含了t[0...j-1]多少次,则答案要求是s包含了t多少次,即bin[s.size()][t.size()]
 *	初始条件:
 		1)若j=0,即t为空字符串,则任意的s都包含了空字符串一次,所以bin[i][0]=1 对于任意的i
 		2)若i=0,即s为空字符串,s不包括任意的字符串(除了空字符串),所以bin[0][j]=0 对于任意的j>=1
 *	按列遍历,即对于每一个t[j-1],扫描一遍s,判断s[i-1]==t[j-1],则第j列相当于是对于任意i,求得s[0..i-1]包含了t[0..j-1]多少次
 		1)若s[i-1]!=t[j-1],则s[0..i-1]包含t[0..j-1]的次数 与 s[0..i-2]包含t[0..j-1]相同的次数,即bin[i][j]=bin[i-1][j]
 		2)若s[i-1]==t[j-1],则s[0..i-1]包含t[0..j-1]的次数 = s[0..i-2]包含t[0..j-1]的次数 + s[0..i-2]包含t[0..j-2]的次数,即bin[i][j]=bin[i-1][j]+bin[i-1][j-1]
 			2.1 s[0..i-2]包含t[0..j-1]的次数主要是因为若s[i-1]==s[i-2],即这个字符连续多次出现,并且已经超过了t的个数,则s[i-1]是否存在并不影响,如s=rabbbbbit,t=rabbit
 			2.2 s[0..i-2]包含t[0..j-2]的次数是因为s[i-1]与t[j-1]之前都不相同,少了s[i-1]就无法匹配,如s=adbdbec,t=abc
 */

int numDistinct(string s, string t)
{
	int lens(s.size()), lent(t.size());
	vector<vector<int>> bin(lens + 1, vector<int>(lent + 1, 0));
	for (int i = 0;i != lens + 1;++i) bin[i][0] = 1;	//初始化
	for (int j = 1;j != lent + 1;++j) bin[0][j] = 0;

	for (int j = 1;j != lent + 1;++j)	//按列遍历
	{
		for (int i = 1;i != lens + 1;++i)
		{
			if (s[i - 1] != t[j - 1]) bin[i][j] = bin[i - 1][j];	//不等于
			else bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];		//等于
		}
	}
	return bin[lens][lent];
}