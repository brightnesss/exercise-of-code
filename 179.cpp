/*
 *	179. Largest Number
 *	Given a list of non negative integers, arrange them such that they form the largest number.
 *	For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *	Note: The result may be very large, so you need to return a string instead of an integer.
 */

/*
 *	使用插入排序法,时间复杂度O(n2)
 *	每一次遍历找到最大的那个字符串
 *	两个字符串相加他们的长度肯定是相等的,可以直接用字符串比较大小的方式进行比较
 */
void subLargestNumber(vector<string> &vecs)
{
	int index(0), len(vecs.size()), maxindex;
	string tmpmax;
	for (int i = 0;i != len;++i)
	{
		tmpmax = vecs[i];
		maxindex = i;
		for (int j = i + 1;j < len;++j)
		{
			string cmp1 = tmpmax + vecs[j], cmp2 = vecs[j] + tmpmax;
			if (cmp2 > cmp1)
			{
				tmpmax = vecs[j];
				maxindex = j;
			}
		}
		swap(vecs[index++], vecs[maxindex]);
	}
}

string largestNumber(vector<int>& nums)
{
	vector<string> vecs;
	for (int num : nums) vecs.push_back(to_string(num));
	subLargestNumber(vecs);
	string ans("");
	if (vecs[0] == "0") return "0";	//如果最大的都是0,说明全是0,直接返回0即可
	for (string s : vecs) ans += s;
	return ans;
}