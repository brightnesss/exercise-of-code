//leetcode No.46 Permutations 

/*
 *	Given a collection of distinct numbers, return all possible permutations. 
 *	For example,
 *	[1,2,3] have the following permutations:
	[
   		[1,2,3],
  		[1,3,2],
  		[2,1,3],
  		[2,3,1],
  		[3,1,2],
  		[3,2,1]
	]
 */


//非常暴力的解法
void permute(vector<vector<int>> &ans, vector<int> nums, vector<int> tmp)
{
	if (nums.empty()) { ans.push_back(tmp);return; }
	for (int i = 0;i != nums.size();++i)
	{
		tmp.push_back(nums[i]);
		vector<int> nextnum = nums;
		nextnum.erase(nextnum.begin() + i, nextnum.begin() + i + 1);
		permute(ans, nextnum, tmp);
		tmp.pop_back();
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	permute(ans, nums, tmp);
	return ans;
}

//用交换替代删除,效率会高一点
void permute(vector<vector<int>> &ans, vector<int> &nums, int begin)
{
	if (begin == nums.size()) { ans.push_back(nums);return; }
	for (int i = begin;i != nums.size();++i)
	{
		swap(nums[i], nums[begin]);
		permute(ans, nums, begin + 1);
		swap(nums[i], nums[begin]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ans;
	vector<int> tmp;
	permute(ans, nums, 0);
	return ans;
}

/*
 *	只用交换的方式,不需要删除
 *	通过每次推入一个新的数,并于之前所有的数分别进行交换,可以组成所有的组合
 */
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ans;
	if (nums.empty()) return ans;
	queue<vector<int>> q;
	q.push(vector<int>{});	//先压入一个空数组
	vector<int> front;
	for (int i = 0;i != nums.size();++i)
	{
		int len(q.size());
		for (int j = 0;j != len;++j)
		{
			front = q.front();
			q.pop();
			int num(front.size());	//需要交换的次数
			front.push_back(nums[i]);	//推入新的数
			q.push(front);	//先把这种情况压入q
			for (int n = 0;n < num;++n)
			{
				swap(front[n], front[num]);	//交换
				q.push(front);	//压入
				swap(front[n], front[num]);	//通过再次交换的方式恢复front为原来的样子,以便下一次继续
			}
		}
	}
	while (!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}
	return ans;
}