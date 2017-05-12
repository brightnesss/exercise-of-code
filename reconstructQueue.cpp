//leetcode No.406 Queue Reconstruction by Height 

/*
 *	Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue. 
 *	Note:
 *	The number of people is less than 1,100. 
 *	Example 

 *	Input:
 *	[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

 *	Output:
 *	[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
{
	map<int, vector<int>> bin; 
	unordered_map<int, int> count; 
	for (auto i : people)
	{
		count.insert(make_pair(i.first, 0));
		bin[i.first].push_back(i.second);
	}
	for (map<int, vector<int>>::iterator it = bin.begin();it != bin.end();++it)
	{
		sort(it->second.begin(), it->second.end());
	}
	vector<pair<int, int>> ans;
	for (int i = 0;i != people.size();++i)
	{
		int minheight = INT_MAX;
		for (auto j : count)
		{
			if (j.second == bin[j.first].front() && j.first < minheight)
			{
				minheight = j.first;
			}
		}
		ans.push_back(make_pair(minheight, bin[minheight].front()));
		bin[minheight].erase(bin[minheight].begin());
		for (unordered_map<int, int>::iterator it=count.begin();it!=count.end();++it)
		{
			if (it->first <= minheight)
			{
				it->second += 1;
			}
		}
	}
	return ans;
}

//A better one
//It is based that:
//Pick out tallest group of people and sort them in a subarray (S).
//Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
//For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
//E.g.
//input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//subarray after step 1: [[7,0], [7,1]]
//subarray after step 2: [[7,0], [6,1], [7,1]]
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first) return true;
	else if (a.first == b.first)
	{
		if (a.second <= b.second) return true;
		else return false;
	}
	else return false;
}

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
{
	sort(people.begin(), people.end(),cmp);
	vector<pair<int, int>> ans;
	for (vector<pair<int, int>>::iterator it = people.begin();it != people.end();++it)
	{
		ans.insert(ans.begin() + it->second, *it);
	}
	return ans;
}