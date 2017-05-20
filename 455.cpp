// leetcode No.455 Assign Cookies

/*
 *	Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each 
 *	child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, 
 *	we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number. 
 */

#include "includelib.h"

int findContentChildren(vector<int>& g, vector<int>& s)
{
	int ans(0);
	list<int> glist, slist;
	for (int i = 0;i != g.size();++i) glist.push_back(g[i]);
	for (int i = 0;i != s.size();++i) slist.push_back(s[i]);
	glist.sort([](int a, int b) {return a > b;});
	slist.sort([](int a, int b) {return a > b;});
	while (!glist.empty() && !slist.empty())
	{
		int cookie = *slist.begin();
		list<int>::iterator it =  find_if(glist.begin(), glist.end(), [cookie](int a) {return a <= cookie;});
		if (it == glist.end()) slist.clear();
		else
		{
			++ans;
			glist.erase(glist.begin(), ++it);
			slist.pop_front();
		}
	}
	return ans;
}