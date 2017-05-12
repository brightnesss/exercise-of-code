//leetcode No.537. Complex Number Multiplication 

/*
 *	Given two strings representing two complex numbers.
 *	You need to return a string representing their multiplication. Note i2 = -1 according to the definition. 
 *	Example :
 *	Input: "1+1i", "1+1i"
 *	Output: "0+2i"
 *	Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 */

string complexNumberMultiply(string a, string b)
{
	//使用stringstream可以方便的从字符串中得到数字
	int ai, aj, bi, bj;
	stringstream sa(a), sb(b), ans;
	char tmp;
	sa >> ai >> tmp >> aj >> tmp;
	sb >> bi >> tmp >> bj >> tmp;
	ans << ai*bi - aj*bj << "+" << aj*bi + ai*bj << "i";
	return ans.str();
}