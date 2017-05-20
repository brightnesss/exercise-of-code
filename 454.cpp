//leetcode No.454 4Sum II 

/*
 *	Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *	To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
 *	All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
 */


/*
 *	只计数有多少种组合,不求组合的具体情况
 *	用map1计数A和B的各个数的和
 *	用map2计数C和D的各个数的和
 *	用map1[i]*map[0-i]就可以得到计数的情况
 */
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int len=A.size();
    unordered_map<int,int> map1,map2;
    for (int i=0;i!=len;++i)
    {
        for (int j=0;j!=len;++j)
        {
            ++map1[A[i]+B[j]];
            ++map2[C[i]+D[j]];
        }
    }
    int ans(0);
    for (auto i:map1)
    {
        ans+=map1[i.first]*map2[-i.first];
    }
    return ans;
}