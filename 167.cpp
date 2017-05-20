// leetcode No.167 Two Sum II - Input array is sorted 

#include "includelib.h"


//使用二分查找，是一个O(nlogn)的复杂度
vector<int>::iterator binarySearch(vector<int>::iterator begin, vector<int>::iterator end, int target)
{
	vector<int>::iterator myend(end);
	while (begin != myend && begin + 1 != myend)
	{
		int shift = (myend - begin) / 2;
		vector<int>::iterator temp = begin + shift;
		if (*temp == target) return temp;
		else if (*temp < target) begin = temp;
		else myend = temp;
	}
	if (myend == end)
	{
		if (*begin == target) return begin;
		else return end;
	}
	else
	{
		if (*begin == target) return begin;
		else if (*myend == target) return myend;
		else return end;
	}
}

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int>::iterator pos(numbers.begin()), firstIter(numbers.begin());
	while (firstIter != numbers.end())
	{
		int temp = target - *firstIter;
		auto secondIter = binarySearch(firstIter + 1, numbers.end(), temp);
		if (secondIter != numbers.end())
		{
			int first = firstIter - pos;
			int second = secondIter - pos;
			return{ first + 1,second + 1 };
		}
		else ++firstIter;
	}
}

//使用前后两个指针逼近，O(n)复杂度
vector<int> twoSum(vector<int>& numbers, int target) {
    int lo=0, hi=numbers.size()-1;
    while (numbers[lo]+numbers[hi]!=target){
        if (numbers[lo]+numbers[hi]<target){
            lo++;
        } else {
            hi--;
        }
    }
    return vector<int>({lo+1,hi+1});
}