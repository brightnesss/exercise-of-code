//leetcode No.423 Reconstruct Original Digits from English

/*
 *	Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
 *	Note:
 *	Input contains only lowercase English letters.
 *	Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
 *	Input length is less than 50,000.

 *	Example 1:
 *	Input: "owoztneoer"

 *	Output: "012"

 *	Example 2:
 *	Input: "fviefuro"

 *	Output: "45"
 */ 

//利用数字的英文中一些独有的字母进行判断
string originalDigits(string s)
{
	vector<int> bin(26, 0);
	for (int i = 0;i != s.size();++i) ++bin[s[i] - 'a'];
	vector<int> ans(10, 0);
	ans[0] = bin['z' - 'a'];
	ans[2] = bin['w' - 'a'];
	ans[4] = bin['u' - 'a'];
	ans[6] = bin['x' - 'a'];
	ans[8] = bin['g' - 'a'];
	ans[7] = bin['s' - 'a'] - ans[6];
	ans[5] = bin['f' - 'a'] - ans[4];
	ans[3] = bin['h' - 'a'] - ans[8];
	ans[1] = bin['o' - 'a'] - ans[0] - ans[2] - ans[4];
	ans[9] = bin['i' - 'a'] - ans[8] - ans[6] - ans[5];
	string tmp;
	for (int i = 0;i != 10;++i)
	{
		for (int j = 0;j != ans[i];++i) tmp += to_string(i);
	}
	return tmp;
}