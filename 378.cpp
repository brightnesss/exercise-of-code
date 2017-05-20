//leetcode No.378 Kth Smallest Element in a Sorted Matrix 

/*
 *	Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 *	Note that it is the kth smallest element in the sorted order, not the kth distinct element. 

 *	Example: 
 	matrix = [
    		[ 1,  5,  9],
    		[10, 11, 13],
    		[12, 13, 15]
		],

	k = 8,

	return 13.

 *	Note: 
 *	You may assume k is always valid, 1 ≤ k ≤ n2.
 */

//用Point来记录是数组的下标
typedef pair<int,int> Point;

struct compare
{
	bool operator()(pair<int, Point> a, pair<int, Point> b)
	{
		return a.first > b.first;
	}
};

int kthSmallest(vector<vector<int>>& matrix, int k) 
{
    typedef pair<int, int> Point;
	priority_queue < pair<int, Point>, vector<pair<int, Point>>, compare > bin;
	int n = matrix.size();
	for (int i = 0;i != n;++i) bin.push(make_pair(matrix[i][0], make_pair(i, 0)));
	int ans;
	Point tmp;
	while (k-- != 0) //弹出的第k个即为答案
	{
		ans = bin.top().first;
		tmp = bin.top().second;
		bin.pop();
		if (tmp.second != n-1) bin.push(make_pair(matrix[tmp.first][tmp.second + 1], make_pair(tmp.first, tmp.second + 1))); //将该行的下一个元素压进
	}
	return ans;
}

//整个算法的复杂度为O(klogn)