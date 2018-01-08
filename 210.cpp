/*
 *	210. Course Schedule II
 *	There are a total of n courses you have to take, labeled from 0 to n - 1.
 *	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *	Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 *	There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

 *	For example:
	2, [[1,0]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

	4, [[1,0],[2,0],[3,1],[3,2]]
	There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
	Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
	Another correct ordering is[0,2,1,3].
 */

/*
 *	和207题差不多,只不过207只判断能否存在这样一个序列,而210要求输出这个序列
 *	还是通过拓扑排序的方法,只需要在207上改一点点
 */

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	map<int, vector<int>> pre;
	vector<int> indegree(numCourses, 0), ans;
	for (int i = 0;i != prerequisites.size();++i)
	{
		pre[prerequisites[i].second].push_back(prerequisites[i].first);
		++indegree[prerequisites[i].first];
	}
	for (int i = 0;i != numCourses;++i)
	{
		bool iszero(false);
		for (int j = 0;j != numCourses;++j)
		{
			if (indegree[j] == 0)
			{
				iszero = true;
				indegree[j] = -1;
				for (int node : pre[j])
				{
					--indegree[node];
				}
				ans.push_back(j);	//将序列存入数组
				break;
			}
		}
		if (!iszero) return vector<int>{};	//若不行,返回一个空数组
	}
	return ans;
}