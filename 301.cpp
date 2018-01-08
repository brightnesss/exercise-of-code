/*
 *	301. Remove Invalid Parentheses
 *	Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 *	Note: The input string may contain letters other than the parentheses ( and ).

 *	Examples:
	"()())()" -> ["()()()", "(())()"]
	"(a)())()" -> ["(a)()()", "(a())()"]
	")(" -> [""]
 */

/*
 *	Key Points:
	Generate unique answer once and only once, do not rely on Set.
	Do not need preprocess.
	Runtime 3 ms.
 *	通过一个计数器count,若char为'(',++count;若char为')',--count.则可以通过count的大小来判断之前的字符串是否是合法的
 *	一旦不合法,我们需要移除一个')'来使其合法,但移动哪一个呢?若有多个')'连续出现,可能会造成重复的情况
 		比如:"())",若两个都分别移除,则形成的"()"重复.所以对于连续多个出现的')',我们只移除第一个')'
 *	通过上面的操作,可以确保前面的字符串是合法的.
 *	但同时,我们需要记录一下最后一个移除的位置last_j,这样只移除last_j之后的')',否则也会出现重复情况
 *	上面的额操作都是对于多余的')'而言的,但若多余的是'(',该怎么操作?
 		只需要将数组翻转,再用同样的操作进行一便就好了	
 */

void subRemoveInvalidParentheses(string s, vector<string> &ans, int last_i, int last_j, vector<char> par)
{
	/*
	 *	消除')'时,par={'(',')'}
	 	消除'('时,par={')','('}
	 *	last_i,last_j分别表示上一次的i和j位置
	 	其中i是遍历到s的位置
	 	j是删除的最后一个位置
	 */
	int count(0);	//用count来记录前面的字符串是否合法
	for (int i = last_i;i != s.size();++i)
	{
		if (s[i] == par[0]) ++count;
		else if (s[i] == par[1]) --count;
		if (count >= 0) continue;	//若合法,继续
		else
		{
			//不合法
			for (int j = last_j;j <= i;++j)
			{
				if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1]))	//首先,j的位置必须是一个')',其次,若是连续的')',只删除第一个,确保不重复
				{
					subRemoveInvalidParentheses(s.substr(0, j) + s.substr(j + 1), ans, i, j, par);
				}
			}
			return;
		}
	}
	//开始删除'('
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	if (par[0] == '(') subRemoveInvalidParentheses(reversed, ans, 0, 0, vector<char>{')', '('});	//par[0]=='(',说明')'已经删除结束了
	else ans.push_back(reversed);	//说明'('和')'都删除结束了,两次翻转使得顺序和s一致
}

vector<string> removeInvalidParentheses(string s)
{
	vector<string> ans;
	subRemoveInvalidParentheses(s, ans, 0, 0, vector<char>{'(', ')'});	
	return ans;
}