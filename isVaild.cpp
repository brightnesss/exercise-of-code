// leetcode No.20 Valid Parentheses

/*
 *	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

bool isValid(string s)
{
	stack<char> bin;
	size_t pos = 0;
	while (pos != s.size())
	{
		if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{') bin.push(s[pos]);
		else
		{
			if (bin.empty()) return false;
			if (s[pos] == ')'&&bin.top() == '(') bin.pop();
			else if (s[pos] == ']'&&bin.top() == '[') bin.pop();
			else if (s[pos] == '}'&&bin.top() == '{') bin.pop();
			else return false;
		}
		++pos;
	}
	if (bin.empty()) return true;
	else return false;
}