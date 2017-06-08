//leetcode No.309 Best Time to Buy and Sell Stock with Cooldown

/*
 *	Say you have an array for which the ith element is the price of a given stock on day i.
 *	Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) 
 *	with the following restrictions:
 *	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

 *	Example:
 *	prices = [1, 2, 3, 0, 2]
 *	maxProfit = 3
 *	transactions = [buy, sell, cooldown, buy, sell]
 */


/*
 *	动态规划,采用两个数组buy,sell分别表示当在第i天买入或卖出时能够获得的最大收益
 *	初始状态:buy[0]=-prices[0],因为买入需要支出,故在第一天买入时,收益为-prices[0]
 *	sell[0]=0,因为第一天没有持有股票,卖出收益为0

 *	状态转移方程:
 *	令delta=prices[i]-prices[i-1],表示第i天与第i-1天的差价
 *	buy[i]=max(sell[i-2]-prices[i],buy[i-1]-delta),即若i天买入,则最后一次卖出肯定时前两天(即隔一天),与第i-1天买入并补第i天的差价.因为是买入,补差价需要支出(即第i-1天买入了,但后悔了,改成第i天买入,需要补差价)
 *	sell[i]=max(buy[i-1]+prices,sell[i-1]+delta),即第i天卖出的收益为i-1天买入第i天卖出,或第i-1天卖出并赚取差价.即第i-1天卖出后悔,改为i天卖出,则收益了差价

 *	最后的结果为sell中的最大值
 */

int maxProfit(vector<int>& prices, int flag = 2)
{
	if (prices.empty()) return 0;
	int n = prices.size();
	vector<int> sell(n), buy(n);
	sell[0] = 0;
	buy[0] = -prices[0];
	for (int i = 1;i != n;++i)
	{
		int delta = prices[i] - prices[i - 1];
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] + delta);
		buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] - delta);
	}
	return *max_element(sell.begin(), sell.end());
}