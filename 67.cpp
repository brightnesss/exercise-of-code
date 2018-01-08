/*
 *	67. Add Binary
 *	Given two binary strings, return their sum (also a binary string).

 *	For example,
 	a = "11"
	b = "1"
	Return "100".
 */

string addBinary(string a, string b)
{
	int lena(a.size() - 1), lenb(b.size() - 1), c(0);	//c表示进位
	string s("");
	while (lena >= 0 || lenb >= 0 || c)
	{
		c += lena >= 0 ? a[lena--] - '0' : 0;
		c += lenb >= 0 ? b[lenb--] - '0' : 0;
		if (c >= 2)
		{
			s = char(c - 2 + '0') + s;
			c = 1;
		}
		else
		{
			s = char(c + '0') + s;
			c = 0;
		}
	}
	return s;
}