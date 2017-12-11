/*
 *	32. Longest Valid Parentheses
 *	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *	For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *	Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

/*
 *	Approach #2 Using Dynamic Programming [Accepted]

 *	Algorithm:
 *	This problem can be solved by using Dynamic Programming. 
 *	We make use of a dp array where iith element of dp represents the length of the longest valid substring ending at ith index. 
 *	We initialize the complete dp array with 0's. Now, it's obvious that the valid substrings must end with ‘)’. 
 *	This further leads to the conclusion that the substrings ending with ‘(’ will always contain '0' at their corresponding dp indices. 
 *	Thus, we update the dp array only when ‘)’ is encountered.

 *	To fill dp array we will check every two consecutive characters of the string and if
 *	s[i]=‘)’ and s[i−1]=‘(’, i.e. string looks like ".......()"
 *	dp[i]=dp[i−2]+2

 *	We do so because the ending "()" portion is a valid substring anyhow and leads to an increment of 2 in the length of the just previous valid substring's length.
 *	s[i]=‘)’ and s[i−1]=‘)’, i.e. string looks like ".......))"

 *	if s[i−dp[i−1]−1]=‘(’ then
 *	dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

 *	The reason behind this is that if the 2nd last ‘)’ was a part of a valid substring (say sub_s),
​​ *	for the last ‘)’ to be a part of a larger substring, there must be a corresponding starting \‘(’ which 
 *	lies before the valid substring of which the 2nd last ‘)’ is a part (i.e. before sub_s)
​​ *	Thus, if the character before subs happens to be ‘(’, we update the dp[i] as an addition of 22 in the length of subs
​​ *	which is dp[i−1]. To this, we also add the length of the valid substring just before the term "(sub_s)" , i.e. dp[i−dp[i−1]−2].
 */

/*
 *	原理就是用一个数组bin来存放截止到index时,最长的连续序列长度
 *	当index-1是(且index是)时,bin[index]=bin[index-2]+2,很容易理解
 *	当index-1是)且index是)时,即可能出现的连续的),则：
 *	若index的)是最长的序列中的一员,则前面肯定有一个(和它对应,那么这个(的位置在哪里呢,就是i-bin[index-1]-1
 *	因为bin[index-1]是目前最长的序列长度,则它前一位肯定是(
 *	在这种情况下,bin[index]=bin[index-1]+bin[index-bin[index-1]-2]+2,相当于由3部分构成：
 *	1. bin[index-1]即截至到目前最长连续最长序列
 *	2. bin[i-bin[index-1]-2]即在这个序列之前的最长序列,可以解决()(())这种情况
 *	3. 2,即新增加的一对序列造成的长度增加
 */
int longestValidParentheses_v2(string s)
{
	vector<int> bin(s.size(), 0);
	for (int i = 1;i != s.size();++i)
	{
		if (s[i - 1] == '('&&s[i] == ')')
		{
			if (i - 2 >= 0)
			{
				bin[i] = bin[i - 2] + 2;
			}
			else bin[i] = 2;
		}
		else if (s[i - 1] == ')'&&s[i] == ')')
		{
			if (i - bin[i - 1] - 1 >= 0 && bin[i - bin[i - 1] - 1] == '(')
			{
				if (i - bin[i - 1] - 2 >= 0) bin[i] = bin[i - 1] + bin[i - bin[i - 1] - 2] + 2;
				else bin[i] = bin[i - 1] + 2;
			}
		}
	}
	return *max_element(bin.begin(), bin.end());
}

/*
 *	Instead of finding every possible string and checking its validity, 
 *	we can make use of stack while scanning the given string to check if the string scanned so far is valid, 
 *	and also the length of the longest valid string. In order to do so, we start by pushing -1−1 onto the stack.

 *	For every ‘(’ encountered, we push its index onto the stack.
 *	For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, 
 *	which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, 
 *	we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, 
 *	and return the length of the longest valid string at the end.
 */

/*
 *	每遇到一个(,就把他的坐标压入栈中
 *	没遇到一个),就从栈中弹出一个坐标,并：
 *	1. 若弹出后,栈为空,则将目前的坐标压入
 *	2. 若不为空,则计算此时的坐标与栈顶的坐标的差
 */
int longestValidParentheses(string s)
{
	stack<int> bin;
	bin.push(-1);
	int ans(0);
	for (int i = 0;i != s.size();++i)
	{
		if (s[i] == '(') bin.push(i);
		else
		{
			bin.pop();
			if (bin.empty()) bin.push(i);
			else ans = max(ans, i - bin.top());
		}
	}
	return ans;
}