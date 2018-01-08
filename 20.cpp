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

bool isValid(string s)
{
	stack<char> bin;
	for (int i = 0;i != s.size();++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') bin.push(s[i]);
		else
		{
			if (bin.empty()) return false;
			char top = bin.top();
			if (s[i] == ')'&&top == '(' || s[i] == ']'&&top == '[' || s[i] == '}'&&top == '{') bin.pop();
			else return false;
		}
	}
	return bin.empty();
}