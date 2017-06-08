//leetcode No.394 Decode String 

/*
 *	Given an encoded string, return it's decoded string. 
 *	The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
 *	Note that k is guaranteed to be a positive integer.
 *	You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *	Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
 *	For example, there won't be input like 3a or 2[4]. 

 *	Examples: 
 *	s = "3[a]2[bc]", return "aaabcbc". 
 *	s = "3[a2[c]]", return "accaccacc".
 *	s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */



string decodeString(string s)
{
	stack<int> numBin;
	stack<string> charBin;
	int len = s.length();
	int numtmp(0);
	bool isnum(false);
	for (int i = 0;i != len;++i)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			isnum = true;
			numtmp = numtmp * 10 + s[i] - '0';
		}
		else
		{
			if (isnum)
			{
				isnum = false;
				numBin.push(numtmp);
				numtmp = 0;
			}
			if (s[i] == '[') charBin.push("[");
			else if (s[i] == ']')
			{
				string tmp, ans;
				while (charBin.top() != "[")
				{
					tmp.insert(0, charBin.top());
					charBin.pop();
				}
				charBin.pop();
				int num = numBin.top();
				numBin.pop();
				for (int i = 0;i != num;++i) ans += tmp;
				charBin.push(ans);
			}
			else
			{
				if (charBin.empty() || charBin.top() == "[") charBin.push(s.substr(i, 1));
				else
				{
					string tmp = charBin.top();
					charBin.pop();
					tmp += s.substr(i, 1);
					charBin.push(tmp);
				}
			}
		}
	}
	
	string ans;
	while (!charBin.empty())
	{
		ans.insert(0, charBin.top());
		charBin.pop();
	}
	return ans;
}