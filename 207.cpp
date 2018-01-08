/*
 *	207. Course Schedule
 *	There are a total of n courses you have to take, labeled from 0 to n - 1.
 *	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *	Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 *	For example:
	2, [[1,0]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

	2, [[1,0],[0,1]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
	So it is impossible.

 *	相当于判断一个有向图是否是有向无环图
 */

/*
 *	用到所谓的拓扑排序法
 	1. 从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出
	2. 从图中删除该顶点和所有以它为起点的有向边
	3. 重复 1 和 2 直到当前的 DAG 图为空或当前图中不存在无前驱的顶点为止,后一种情况说明有向图中必然存在环.
 */

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
	map<int, vector<int>> pre;
	vector<int> indegree(numCourses, 0);
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
				break;
			}
		}
		if (!iszero) return false;
	}
	return true;
}