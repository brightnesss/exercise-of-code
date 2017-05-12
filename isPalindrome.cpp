//leetcode No.125 Valid Palindrome 

/*
 *	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 
 *	For example,
 *	"A man, a plan, a canal: Panama" is a palindrome.
 *	"race a car" is not a palindrome. 
 *	Note:
 *	Have you consider that the string might be empty? This is a good question to ask during an interview.
 *	For the purpose of this problem, we define empty string as valid palindrome. 
 */




bool isPalindrome(string s)
{
	if (s.empty()) return true;
	int begin(0), end(s.size() - 1);
	string pattern("0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	string nums("0123456789");
	while (true)
	{
		while (begin != s.size() && pattern.find(s[begin]) == string::npos) ++begin;
		while (end != -1 && pattern.find(s[end]) == string::npos) --end;
		if (begin >= end) break;
		else
		{
			if (nums.find(s[begin]) == string::npos && nums.find(s[end]) == string::npos)
			{
				if (abs(s[begin] - s[end]) == 0 || abs(s[begin] - s[end]) == 32)
				{
					++begin;
					--end;
				}
				else return false;
			}
			else
			{
				if (s[begin] == s[end])
				{
					++begin;
					--end;
				}
				else return false;
			}
		}
	}
	return true;
}