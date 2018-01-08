/*
 *	188. Best Time to Buy and Sell Stock IV
 *	Say you have an array for which the ith element is the price of a given stock on day i.
 *	Design an algorithm to find the maximum profit. You may complete at most k transactions.

 *	Note:
 *	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

/*
 *	同best time to buy and sell stock 3类似,只不过需要将bin的大小设置为2k
 *	同时需要注意到的一点就是,若k>prices.size()/2,说明用k次交易可以交易参加每一次的交易,
 	问题相当于退化到了best time to buy and sell stock2,即不限交易次数,用2的方法可以直接得到解
 */

int maxProfit(int k, vector<int>& prices) 
{
	if (k < 1 || prices.size() < 2) return 0;
	int len(prices.size());
	if (k > len / 2)
	{
		int ans(0);
		for (int i = 1;i != len;++i)
		{
			ans += max(prices[i] - prices[i - 1], 0);
		}
		return ans;
	}
	vector<vector<int>> bin(2, vector<int>(2 * k, 0));
	for (int i = 0;i != 2 * k;++i)
	{
		if (i % 2 == 0) bin[0][i] = INT_MIN;
	}
	int cur(0), next(1);
	for (int i = 0;i != prices.size();++i)
	{
		bin[next][0] = max(bin[cur][0], -prices[i]);
		int ratio(1);
		for (int j = 1;j != 2 * k;++j)
		{
			bin[next][j] = max(bin[cur][j], bin[cur][j - 1] + ratio*prices[i]);
			ratio *= -1;
		}
		swap(cur, next);
	}
	int ans(bin[cur][1]);
	for (int i = 1;i < 2 * k;i += 2)
	{
		ans = max(ans, bin[cur][i]);
	}
	return ans;
}

//同样的动态规划
int maxProfit(int k, vector<int>& prices)
{
	int len(prices.size());
	if (k < 1 || len < 2) return 0;
	if (k > len / 2)
	{
		int ans(0);
		for (int i = 1;i != len;++i)
		{
			ans += max(prices[i] - prices[i - 1], 0);
		}
		return ans;
	}
	vector<int> hold(k, INT_MIN), release(k, 0);
	for (int i = 0;i != len;++i)
	{
		for (int j = k - 1;j >= 0;--j)
		{
			release[j] = max(hold[j] + prices[i], release[j]);
			if (j == 0) hold[0] = -prices[i];
			else hold[j] = max(hold[j], release[j - 1] - prices[i]);
		}
	}
	return release[k - 1];
}