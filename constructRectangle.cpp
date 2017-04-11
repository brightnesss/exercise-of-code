// leetcode No.492 Construct the Rectangle

#include "includelib.h"

vector<int> constructRectangle(int area)
{
	double l = sqrt(area);
	if (l == floor(l) == ceil(l))
	{
		int length = l;
		vector<int> ans(2, l);
		return ans;
	}
	else
	{
		int length = ceil(l);
		int width = floor(l);
		for (;length != area;++length)
		{
			for (;width != 1;--width)
			{
				if (length*width < area) break;
				else if (length*width == area)
				{
					vector<int> ans;
					ans.push_back(length);
					ans.push_back(width);
					return ans;
				}
				else continue;
			}
		}
		vector<int> ans;
		ans.push_back(length);
		ans.push_back(1);
		return ans;
	}
}