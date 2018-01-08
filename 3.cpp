/*
 *	3. Longest Substring Without Repeating Characters
 *	Given a string, find the length of the longest substring without repeating characters.

 *	Examples:
 *	Given "abcabcbb", the answer is "abc", which the length is 3.
 *	Given "bbbbb", the answer is "b", with the length of 1.
 *	Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 *	动态规划,空间复杂度O(n2),Memory Limit Exceeded
 *	使用二维数组bin来表示起始位置i,终止位置j的substring包含的最长不重复字串长度
 *	若bin[i][j]中包含重复字符,其长度为-1,
 *	否则,其长度为bin[i][j]=bin[i][j-1]+1
 */

int lengthOfLongestSubstring(string s)
{
	if (s.empty()) return 0;
	int len(s.size());
	vector<vector<int>> bin(len, vector<int>(len, 1));
	int row, col, ans(1);
	for (int i = 1;i != len;++i)
	{
		row = 0;
		col = i;
		while (col != len)
		{
			if (bin[row][col - 1] == -1)
			{
				++row;
				++col;
			}
			else
			{
				bin[row][col] = bin[row][col - 1] + 1;
				for (int j = row;j != col;++j)
				{
					if (s[j] == s[col])
					{
						bin[row][col] = -1;
						break;
					}
					else continue;
				}
				ans = max(ans, bin[row][col]);
				++row;
				++col;
			}
		}
	}
	return ans;
}

/*
 *	two-point,时间复杂度O(n2),空间复杂度O(1)
 *	使用两个指针,begin表示无重复的子序列的开始位置,end表示无重复子序列的结束位置
 *	每次end右移一位时,都将该位与之前所有的字符进行比较,若没有重复,则说明这一段都是无重复的,可以继续后移
 *	若有重复
 		1)则先计算这一段的长度,len=end-begin(因为不包含end,所以不用+1),并将该长度与目前最长的ans比较
 		2)begin=index+1,其中index使得s[index]==s[end],即将begin设置为index的下一位,则可以保证新的begin到end这一段是无重复的
 */
int lengthOfLongestSubstring(string s)
{
	if (s.empty()) return 0;
	int begin(0), end(1), ans(0), len(s.size());
	while (end < len)
	{
		for (int i = begin;i != end;++i)
		{
			if (s[i] == s[end])
			{
				ans = max(ans, end - begin);
				begin = i + 1;
				break;
			}
		}
		++end;
	}
	ans = max(ans, end - begin);
	return ans;
}