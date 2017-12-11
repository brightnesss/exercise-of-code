/*
 *	10. Regular Expression Matching
 *	Implement regular expression matching with support for '.' and '*'.

 	'.' Matches any single character.
 	'*' Matches zero or more of the preceding element.

 *	The matching should cover the entire input string (not partial).

 *	The function prototype should be:
 *	bool isMatch(const char *s, const char *p)

 *	Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true
 */

//Note: '*'不会单独出现,'*'代表的是他之前的那个字母可能出现0次或多次

/*
 *	使用bin[i][j]来表示s[0...i-1]与p[0...j-1]是否能够匹配,则答案为bin中最后一个
 *	若p[j - 1]为'*', 则只要s[i - 1]与p[j - 1]相等并且他们之前的序列能够匹配,则bin[i][j] = true, 如下:
 *	if p[j - 1] != '*'
 		bin[i][j] = bin[i - 1][j - 1] && s[i - 1] == p[j - 1]
 *	if p[j - 1] == '*', 假设p[j - 2]字符为x
 		bin[i][j] is true iff any of the following is true
		1) "x*" repeats 0 time and matches empty: bin[i][j - 2]	即x*出现了0次,即x一次都没有出现,则相当于可以直接将这两个字符跳过,bin[i][j]=bin[i][j-2]
		2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && bin[i - 1][j]	即若x*实际上出现了并出现了多次, 则只要s[i - 1]==x同时bin[i-1][j]为true, 则bin[i][j]=true
 * 	'.' matches any single character
 */

bool isMatch(string s, string p) 
{
    int m(s.size()+1),n(p.size()+1);
    vector<vector<bool>> bin(m,vector<bool>(n,false));
    bin[0][0]=true;	//s与p皆为空时,肯定是匹配的
    for (int i=1;i!=n;++i)
    {
    	//初始化bin[0],即当s为空时,p的匹配.容易得到此时若想匹配,只能是也为空,即一定要是p==''或p='x*y*z*...w*',即任一一个字符后面肯定都要跟随'*'
        if (i>1 && p[i-1]=='*' && bin[0][i-2]) bin[0][i]=true;
    }
    
    for (int i=1;i!=m;++i)
    {
        for (int j=1;j!=n;++j)
        {
            if (p[j-1]!='*')
            {
            	//若p[j-1]!='*'
                if (s[i-1]==p[j-1] && bin[i-1][j-1]) bin[i][j]=true;	//只需要s[i-1]==p[j-1]
                else if (p[j-1]=='.' && bin[i-1][j-1]) bin[i][j]=true; 	//因为p[j-1]是'.',可以匹配任意s中的字符
            }
            else
            {
            	//若p[j-1]=='*'
                if (bin[i][j-2]) bin[i][j]=true;	//情况1) "x*"出现了0次
                else if (s[i-1]==p[j-2] && bin[i-1][j]) bin[i][j]=true;		//情况2) "x*"出现了多次
                else if (p[j-2]=='.' && bin[i-1][j]) bin[i][j]=true;	//同样是情况2) "x*"出现了多次
            }
        }
    }
    return bin[m-1][n-1];
}