/*
 *	187. Repeated DNA Sequences
 *	All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
 	When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *	Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 *	For example,
	Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
	Return:
	["AAAAACCCCC", "CCCCCAAAAA"].
 */

/*
 *	分别将ACTG编码为0,1,2,3,这样他们的二进制分别为00,01,10,11,只需两位就可以表示
 	将10个碱基编码为这样的二进制序列,则每一种组合都是独一无二的
 *	从头开始,保证组合中共有10个碱基对,方式和两点法差不多,即若长度大于10,则将begin后移,删掉begin的值,保证总长为10
 	这不过在这里的操作方式是通过按位与
 		1)因为每一个碱基对用2位进行编码,则10个总共有20位
 		2)0xF,即16进制的F二进制表示为1111,即4位,则5个0xF就可以表示整个10个碱基对
 		3)通过10个碱基对与0xFFFFF按位与,可将高位的1删除,相当于将beign后移并删除begin的值
 		  因为若已经有10个碱基对了,再来一个,就有22位,而0xFFFFF只有20位,则前面两位按位与肯定为0,不论它们的值是多少
 */
vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> ans;
	if (s.size() < 11) return ans;
	map<char, int> mchar;
	map<int, int> mint;
	mchar['A'] = 0;
	mchar['C'] = 1;
	mchar['T'] = 2;
	mchar['G'] = 3;
	int dna(0), len(s.size());
	for (int i = 0;i != 9;++i) dna = dna << 2 | mchar[s[i]];	//先编码9个碱基对
	for (int i = 9;i != len;++i)
	{
		dna = dna << 2 & 0xFFFFF | mchar[s[i]];	//dna<<2&0xFFFFF将begin后移并删除begin的值,|mchar[s[i]]是补充后面的值
		if (++mint[dna] == 2) ans.push_back(s.substr(i - 9, 10));	//若这个值刚好有两个,说明重复了,但为了ans中不出现多次重复,只有出现第一次重复时(值为2)才会压入ans中
	}
	return ans;
}