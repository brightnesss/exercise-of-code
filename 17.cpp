/*
 *	17. Letter Combinations of a Phone Number
 *	Given a digit string, return all possible letter combinations that the number could represent.
 *	A mapping of digit to letters (just like on the telephone buttons) is given below.
 *	Input:Digit string "23"
 *	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 *	就是手机输入法中的九键
 */


/*
 *	先用一个map来存放各个按键对应的字母有哪些
 *	对于一个新来的按键,现在map中找到它对应的按键
 *	然后将queue中的所有已有的字符串都加上这个按键的字母
 */
vector<string> letterCombinations(string digits)
{
	map<char, string> phone;
	phone['2'] = "abc";
	phone['3'] = "def";
	phone['4'] = "ghi";
	phone['5'] = "jkl";
	phone['6'] = "mno";
	phone['7'] = "pqrs";
	phone['8'] = "tuv";
	phone['9'] = "wxyz";
	queue<string> bin;
	for (int i = 0;i != digits.size();++i)
	{
		if (phone.find(digits[i]) != phone.end())
		{
			string value = phone[digits[i]];	//value是按键对应的所有可能的字母
			if (bin.empty())
			{
				//若bin是空的,实际上就是第一个按键
				for (int j = 0;j != value.size();++j) bin.push(value.substr(j,1));	//将按键所有的字母都分别push入queue
			}
			else
			{
				//不为空,对与queue中每一个string,都在后面加上这个按键所有可能的字母
				int len = bin.size();
				for (int num = 0;num != len;++num)
				{
					string front = bin.front();	//queue中已有的字符串
					bin.pop();
					for (int j = 0;j != value.size();++j)
					{
						bin.push(front + value[j]);	//加上所有可能的字母
					}
				}
			}
		}
		else continue;
	}
	vector<string> ans;
	while (!bin.empty())
	{
		ans.push_back(bin.front());
		bin.pop();
	}
	return ans;
}