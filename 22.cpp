//leetcode No.22 Generate Parentheses 

/*
 *	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
 *	For example, given n = 3, a solution set is: 
 	[
 	  "((()))",
  	  "(()())",
      "(())()",
      "()(())",
      "()()()"
 	]
 */



void parenthesis(vector<string> &ans, string tmp, stack<char> bin, int curr, const int n)
{
	if (curr == 0)
	{
		while (!bin.empty())
		{
			tmp += ')';
			bin.pop();
		}
		ans.push_back(tmp);
	}
	else
	{
		if (bin.empty())
		{
			bin.push('(');
			tmp += '(';
			parenthesis(ans, tmp, bin, curr - 1, n);
		}
		else
		{
			bin.push('(');
			tmp += '(';
			parenthesis(ans, tmp, bin, curr - 1, n);

			bin.pop();
			tmp.pop_back();
			bin.pop();
			tmp += ')';
			parenthesis(ans, tmp, bin, curr, n);

		}
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> ans;
	string tmp;
	stack<char> bin;
	parenthesis(ans, tmp, bin, n, n);
	return ans;
}

// a better one
vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}
    
void addingpar(vector<string> &v, string str, int n, int m){
    if(n==0 && m==0) {
        v.push_back(str);
        return;
    }
    if(m > 0){ addingpar(v, str+")", n, m-1); }
    if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
}