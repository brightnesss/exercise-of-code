//leetcode No.582 Kill Process 

/*
 *	Given n processes, each process has a unique PID (process id) and its PPID (parent process id). 
 *	Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. 
 *	Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
 *	We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID. 
 *	Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. 
 *	You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.
 */

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
{
	//用一个map把process的树关系保存起来
	//之后用广度优先搜索完成
	unordered_map<int, vector<int>> map;
	for (int i = 0;i != pid.size();++i) map[ppid[i]].push_back(pid[i]);
	queue<int> bin;
	bin.push(kill);
	vector<int> ans;
	int tmp;
	while (!bin.empty())
	{
		tmp = bin.front();
		bin.pop();
		ans.push_back(tmp);
		for (auto i : map[tmp]) bin.push(i);
	}
	return ans;
}