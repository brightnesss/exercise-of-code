//leetcode No.547 Friend Circles 

/*
 *	There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
 *	For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. 
 *	And we defined a friend circle is a group of students who are direct or indirect friends. 
 *	Given a N*N matrix M representing the friend relationship between students in the class. 
 *	If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. 
 *	And you have to output the total number of friend circles among all the students. 
 */

//相当于在一个无向图中搜索联通子图的个数

int findCircleNum(vector<vector<int>>& M)
{
	int n = M.size();
	vector<bool> visited(n, false);
	queue<int> bin;
	int ans(0);
	for (int i = 0;i != n;++i)
	{
		if (visited[i]) continue;
		else
		{
			++ans;
			visited[i] = true;
			bin.push(i);
			int head;
			while (!bin.empty())
			{
				head = bin.front();
				bin.pop();
				for (int j = i;j != n;++j)
				{
					if (M[head][j] == 1 && !visited[j])
					{
						visited[j] = true;
						bin.push(j);
					}
					else continue;
				}
			}
		}
	}
	return ans;
}