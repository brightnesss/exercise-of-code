/*
 *	58. Length of Last Word
 *	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *	If the last word does not exist, return 0.

 *	Note: A word is defined as a character sequence consists of non-space characters only.
 */

int lengthOfLastWord(string s)
{
	while (s.back() == ' ') s.pop_back();
	size_t pos = s.rfind(' ');
	return s.size() - pos - 1;
}