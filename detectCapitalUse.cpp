// leetcode No.520 Detect Capital

/*
 *	Given a word, you need to judge whether the usage of capitals in it is right or not. 
 *	We define the usage of capitals in a word to be right when one of the following cases holds: 
 *	1. All letters in this word are capitals, like "USA".
 *	2. All letters in this word are not capitals, like "leetcode".
 *	3. Only the first letter in this word is capital if it has more than one letter, like "Google".
 *	Otherwise, we define that this word doesn't use capitals in a right way. 
 */

#include "includelib.h"

bool detectCapitalUse(string word)
{
	//找大写字母，若没找到，则全由小写字母构成，合法
	//找小写字母，若没找到，则全由大写字母构成，合法
	//反向找大写字母，若找到且为第一个字母，合法
	//其余全非法
	string bitCapital("QWERTYUIOPASDFGHJKLZXCVBNM");
	string smallCapital("qwertyuiopasdfghjklzxcvbnm");
	if (word.find_first_of(bitCapital) == string::npos || word.find_first_of(smallCapital) == string::npos)	return true;
	else if (word.find_last_of(bitCapital) == 0) return true;
	else return false;
}