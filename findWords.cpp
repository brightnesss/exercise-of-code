#include "includelib.h"

// leetcode No.500 Keyboard Row

// 若一个单词只由一行的字母构成，即其他两行的任何字母都不会出现
// 在该单词中查找其他两行的字母，若出现了，则该单词一定不是只由一行字母构成的单词

vector<string> findWords(vector<string>& words)
{
	vector<string> ans;
	string firstRow("qwertyuiopQWERTYUIOP"), secondRow("asdfghjklASDFGHJKL"), thirdRow("zxcvbnmZXCVBNM");
	for (vector<string>::iterator witer = words.begin();witer != words.end();++witer)
	{
		size_t posFirstRow = (*witer).find_first_of(firstRow);
		size_t posSecondRow = (*witer).find_first_of(secondRow);
		size_t posThirdRow = (*witer).find_first_of(thirdRow);
		if (posFirstRow != string::npos && posSecondRow == string::npos && posThirdRow == string::npos)
		{
			ans.push_back(*witer);	//只由第一行构成
		}
		else if (posFirstRow == string::npos && posSecondRow != string::npos && posThirdRow == string::npos)
		{
			ans.push_back(*witer);	//只由第二行构成
		}
		else if (posFirstRow == string::npos && posSecondRow == string::npos && posThirdRow != string::npos)
		{
			ans.push_back(*witer);	//只由第三行构成
		}
		else continue;
	}
	return ans;
}