//leetcode No.216 Combination Sum III 

/* 
 *	Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 
 *	Example 1:
 *	Input: k = 3, n = 7
 *	Output: 
 *	[[1,2,4]]

 *	Example 2:
 *	Input: k = 3, n = 9
 *	Output: 
 *	[[1,2,6], [1,3,5], [2,3,4]]
 */

//每一位都不能重复,即数字1-9只能出现一次
//用递归的方法,从最小的数开始,直到最大的数,遍历搜索

void combineSum3(vector<vector<int>> &ans, vector<int> &tmp, int curr, const int k, const int n)
{
	if (curr < k) tmp[k - curr] = tmp[k - curr - 1] + 1;
	if (tmp[k - curr] > 9) return;
	if (curr == 1)
	{
		for (int i = tmp[k - curr];i != 10;++i)
		{
			tmp[k - curr] = i;
			int sum = accumulate(tmp.begin(), tmp.end(), 0);
			if (sum == n) ans.push_back(tmp);
			else if (sum > n) break;
			else continue;
		}
		return;
	}
	else
	{
		for (int i = tmp[k - curr];i != 10;++i)
		{
			tmp[k - curr] = i;
			combineSum3(ans, tmp, curr - 1, k, n);
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	for (int i = 0;i != k;++i) tmp.push_back(i + 1);
	combineSum3(ans, tmp, k, k, n);
	return ans;
}

//应用backtracking的方法
//效率确实会高很多
void subcombinationSum3(vector<int>& bin, int begin, vector<vector<int>>& ans, vector<int>& tmp, const int k, int n)
{
	if (tmp.size() > k) return;	//当前数组大小大于k,返回
	else if (tmp.size() == k&&n == 0)
	{
		//当前数组大小等于k且和为n,是我们想要的答案
		ans.push_back(tmp);
		return;
	}
	if (n <= 0) return;	//当前数组内的和已经大于n了,返回

	for (int i=begin;i!=bin.size();++i)
	{
		tmp.push_back(bin[i]);
		subcombinationSum3(bin, i + 1, ans, tmp, k, n - bin[i]);
		tmp.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> ans;
	vector<int> bin{ 1,2,3,4,5,6,7,8,9 };
	vector<int> tmp;
	subcombinationSum3(bin, 0, ans, tmp, k, n);
	return ans;
}