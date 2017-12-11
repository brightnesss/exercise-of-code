/*
 *	240. Search a 2D Matrix II
 *	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 *	Integers in each row are sorted in ascending from left to right.
 *	Integers in each column are sorted in ascending from top to bottom.

 *	For example,
 *	Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

 *	Given target = 5, return true.
 *	Given target = 20, return false.
 */

//O(mlogn)
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty() || matrix[0].empty()) return false;
	int m(matrix.size()), n(matrix[0].size());
	for (int i = 0;i != m;++i)
	{
		if (target < matrix[i][0]) return false;
		if (target > *matrix[i].rbegin()) continue;
		if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
	}
	return false;
}

//O(m+n)
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if (matrix.empty() || matrix[0].empty()) return false;
	int m(matrix.size()), n(matrix[0].size());
	int i = 0, j = n - 1;	//先确定每一行的最大数是不是大于target
	while (i < m && j >= 0) 
	{
		if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) --j;	//若是,则缩小列数
        else ++i;
    }
    return false;
}