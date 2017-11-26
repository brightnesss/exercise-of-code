// leetcode No.189 Rotate Array

/*
 *	Rotate an array of n elements to the right by k steps.
 *	For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
 */

void rotate(vector<int>& nums, int k)
{
	if (k%nums.size() == 0) return;
	k %= nums.size();
	vector<int> tmp;
	for (int i = 0;i != k;++i) tmp.push_back(nums[i]);
	for (int i = nums.size() - 1;i >= k;--i)
	{
		nums[(i + k ) % nums.size()] = nums[i];
	}
	for (int i = 0;i != k;++i) nums[(i + k) % nums.size()] = tmp[i];
	return;
}

void rotate(vector<int>& nums, int k) 
{
    map<int,int> bin;
    int index,len(nums.size());
    if (k%len==0) return;
    for (int i=0;i!=len;++i)
    {
        index=(i+k)%len;
        bin[index]=nums[i];
    }
    for (map<int,int>::iterator it=bin.begin();it!=bin.end();++it)
    {
        nums[it->first]=it->second;
    }
    return;
}