//leetcode No.137. Single Number II 

/*
 *	Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one. 
 *	Note:
 *	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
 */

/*
 *	对于类似在数组nums中,有一些数分别出现了m次,只有一个数出现了n次,求这个数 ps:m>n且m%n!=0
 *	有通解如下:

 *	在c++中,可以用一个32位长度的数组count记录所有位上的和

 *	我们假设,nums中有k个数分别出现了m次,其中,在位i上,有x个数为1,有y个数为0
 *	只有一个数出现了n次,在位i上,不知道这个数为1还是0,设为z(z = 1或z = 0)

 *	则根据上述假设,有:x+y=k,且count[i] = m * x + 0 * y + n * z,即count[i] = m * x + n * z
 *	解上述方程,有:z = (count[i] % m) / n

 *	可以通过对每一位求解上述方程,得到每一位的z,组合起来即为答案
 */

/*
 *	在该题中,m=3,n=1
 */

int singleNumber(vector<int>& nums)
{
	vector<int> count(32,0);
	for (int i = 0;i != 32;++i)
	{
		for (int j : nums)
		{
			if ((j>>i)&1) ++count[i];
		}
	}

	int ans(0);
	for (int i = 0;i != 32;++i)
	{
		ans |= (count[i]%3) << i;
	}
	return ans;
}