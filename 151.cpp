/*
 *	151. Reverse Words in a String
 *	Given an input string, reverse the string word by word.

 *	For example,
	Given s = "the sky is blue",
	return "blue is sky the".

 *	Update (2015-02-12):
 *	For C programmers: Try to solve it in-place in O(1) space.
 */

//时间空间都是O(n)
void reverseWords(string &s)
{
	if (s.empty()) return;
	vector<string> vecs;
	int begin(0), end(0);
	while (begin != string::npos)
	{
		begin = s.find_first_not_of(' ', end);
		if (begin == string::npos) break;
		end = s.find_first_of(' ', begin);
		if (end != string::npos) vecs.push_back(s.substr(begin, end - begin));
		else vecs.push_back(s.substr(begin));
	}
	s.clear();
	if (vecs.empty()) return;
	reverse(vecs.begin(), vecs.end());
	for (int i = 0;i != vecs.size();++i)
	{
		if (i == 0) s += vecs[i];
		else
		{
			s += " ";
			s += vecs[i];
		}
	}
}