/*
 *	91. Decode Ways
 *	A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *	'A' -> 1
 *	'B' -> 2
 *	...
 *	'Z' -> 26
 *	Given an encoded message containing digits, determine the total number of ways to decode it.

 *	For example,
 *	Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *	The number of ways decoding "12" is 2.
 */

/*
 *	动态规划,使用一个数组vec来存放截至到index位,有多少种解码方法,vec初始全部为0
 *	首先有两种特殊情况:
 		1)s为空,则返回0
 		2)s以0开头,则也没有任何一种解码方式,返回0
 *	若前index位有n种解码方式,则当第index+1位加入后,有两种情况
 		1)第index+1位可以单独解码,即为1..9中的一个,则此时vec[index+1]+=vec[index]
 		2)第index位和index+1位可以合起来组成一个两位数,即10..26中的一个,则vec[index+1]+=vec[index-1]
 */
int numDecodings(string s)
{
	if (s.empty()) return 0;
	if (s[0] == '0') return 0;
	int len(s.size());
	vector<int> vec(len + 1, 0);
	set<string> st;
	string substr;
	for (int i = 0;i != 26;++i) st.insert(to_string(i + 1));
	vec[0] = vec[1] = 1;	//初始情况
	for (int i = 1;i != len;++i)
	{
		substr = s.substr(i, 1);
		if (st.find(substr) != st.end()) vec[i + 1] += vec[i];	//情况1
		substr = s.substr(i - 1, 2);
		if (st.find(substr) != st.end()) vec[i + 1] += vec[i - 1];	//情况2
	}
	return vec[len];
}