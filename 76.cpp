/*
 *	76. Minimum Window Substring
 *	Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

 *	For example,
	S = "ADOBECODEBANC"
	T = "ABC"
	Minimum window is "BANC".

 *	Note:
 *	If there is no such window in S that covers all characters in T, return the empty string "".
 *	If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

/*
 *	使用一个vector map来记录下t中所有出现的字母的次数,map的大小是128是因为所有的大小写字符的ASCII都在128内
 *	1.先统计t中的字母出现次数
 *	2.使用count来记录当前还有几个t中的字母没有出现,初始化为t的长度
 	begin来记录最终的答案的起始字母位置
 	len记录最终答案的长度
 	pstart和pend来表示遍历的两个指针,分别指向开头和结尾
 *	3.进行下面的额循环
 		1)先要扩展pend,使得s[pstart...pend]表示的字符串出现了t中所有的字符,此时count=0
 		每出现一次,将map中的字符次数-1,若map中对应字符的次数>=0,说明这个字符还需要继续出现,count--,
 		否则若map中对应字符出现次数已经<0,说明这个字符再出现已经没意义了,count不需要改变
 		2)当count=0后,开始移动pstart,尽可能的缩短长度,每后移一次pstart,map中对应s[pstart]的字符次数都要+1
 		若map中对应s[pstart]的字符次数为0,说明这次再将pstart移动后,这个字符已经需要再次出现了,此时count++

 *	需要注意的是,这样做那些t中没有出现但在s中出现的字符丝毫不会有影响,因为对于该题,pend一定在pstart之后,
 	那些没有出现在t中的字符,在pend遍历到的时候-1,在pstart遍历到的时候+1,所以他们一定是在0保持不变
 */

string minWindow(string s, string t)
{
	vector<int> map(128, 0);
	for (char c : t) ++map[c];
	int count(t.size()), begin(0), len(INT_MAX), pstart(0), pend(0);
	while (pend < s.size())
	{
		--map[s[pend]];
		if (map[s[pend]] >= 0)
		{
			--count;
		}
		++pend;
		while (count == 0)
		{
			if (pend - pstart < len)
			{
				len = pend - pstart;
				begin = pstart;
			}
			if (map[s[pstart]] == 0) ++count;
			++map[s[pstart]];
			++pstart;
		}
	}
	return len == INT_MAX ? "" : s.substr(begin, len);
}

//上面的写法都是将++,--等操作分开进行,但实际上写起来很拗口
//若变为下面的形式,看起来很复杂,其实会更简单且直接
string minWindow_v2(string s, string t)
{
	vector<int> map(128, 0);
	for (char c : t) ++map[c];
	int count(t.size()), begin(0), len(INT_MAX), pstart(0), pend(0);
	while (pend < s.size())
	{
		if (map[s[pend++]]-- > 0) --count;
		while (count == 0)
		{
			if (pend - pstart < len)
			{
				len = pend - pstart;
				begin = pstart;
			}
			if (map[s[pstart++]]++ == 0) ++count;
		}
	}
	return len == INT_MAX ? "" : s.substr(begin, len);
}