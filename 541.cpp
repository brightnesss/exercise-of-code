// leetcode No.541 Reverse String 2

/*
 *	Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there 
 *	are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k 
 *	characters and left the other as original. 
 */

string reverseStr(string s, int k)
{
	stack<char> reverseStack;
	queue<char> bin;
	size_t pos(0);
	int ktmp = 1;
	bool inre(true);
	for (;pos != s.size();++pos)
	{
		if (inre)
		{
			reverseStack.push(s[pos]);
			++ktmp;
			if (ktmp <= k) inre = true;
			else
			{
				inre = false;
				ktmp = 1;
				while (!reverseStack.empty())
				{
					char ctmp = reverseStack.top();
					bin.push(ctmp);
					reverseStack.pop();
				}
			}
			continue;
		}
		else
		{
			bin.push(s[pos]);
			if ((pos + 1) % (2 * k) == 0) inre = true;
			else inre = false;
		}
	}
	string ans;
	while (!reverseStack.empty())
	{
		char tmp = reverseStack.top();
		bin.push(tmp);
		reverseStack.pop();
	}

	while (!bin.empty())
	{
		ans += bin.front();
		bin.pop();
	}
	return ans;
}