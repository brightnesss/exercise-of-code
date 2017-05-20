// leetcode No.447 Number of Boomerangs

int numberOfBoomerangs(vector<pair<int, int>>& points)
{
	int ans(0);

	for (int i = 0;i != points.size();++i)
	{
		// 对每一个点，都遍历一遍以该点为起点，其他点与该点的距离
		unorder_map<int,int> bin(points.size())
		for (int j = 0;j != points.size();++j)
		{
			if (i == j) continue;	//自己与自己不计算

			//	key就是两点间距离的平方
			int key = (vector[i].first - vector[j].first) * (vector[i].first - vector[j].first) \ 
			+ (vector[i].second - vector[j].second) * (vector[i].second - vector[j].second);

			//	这个距离的点数目+1
			bin[key] += 1;
		}

		for (auto index : bin)
		{
			//	遍历结束后，计算每一个距离上的点数，即求组合数，n个数中算两个，计算顺序
			if (index.second > 1) ans += index.second * (index.second - 1);
		}
	}

	return ans;
}