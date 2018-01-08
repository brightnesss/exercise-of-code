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

// a better one
int isalphanumeric(const char &a)
{
	if (a >= 48 && a <= 57) return 1; //数字
	else if (a >= 65 && a <= 90) return 2; //字母
	else if (a >= 97 && a <= 122) return 2;
	else return 0; //非数字和字母
}

bool isPalindrome(string s)
{
	int begin(0), end(s.size() - 1);
	int tmpa, tmpb;
	while (begin <= end)
	{
		tmpa = isalphanumeric(s[begin]);
		tmpb = isalphanumeric(s[end]);
		if ((tmpa | tmpb) == 3) return false; //如果是一个数字和一个字母
		else if (tmpa && tmpb)
		{
			//如果两个都是有效的
			if (s[begin] == s[end] || abs(s[begin] - s[end]) == 32) //大小写字母也判定为相同的,例如'a'和'A'是一样的
			{
				++begin;
				--end;
			}
			else return false;
		}
		else
		{
			if (!tmpa) ++begin;
			if (!tmpb) --end;
		}
	}
	return true;
}

//第二次写的时候的方法
bool isPalindrome(string s)
{
	int index(0), end(0);
	while (index < s.size())
	{
		char c = s[index];
		if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9')
		{
			if (c >= 'a'&&c <= 'z') c = c - 'a' + 'A';
			s[end] = c;
			++index;
			++end;
		}
		else ++index;
	}
	s = s.substr(0, end);
	string sreverse = s;
	reverse(sreverse.begin(), sreverse.end());
	return s == sreverse;
}