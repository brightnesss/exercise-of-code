//leetcode No.401 Binary Watch

/*
 *	A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 *	Each LED represents a zero or one, with the least significant bit on the right.
 */

vector<string> readBinaryWatch(int num)
{
	bitset<10> bit;
	vector<string> ans;
	for (int hour = 0;hour != 12;++hour)
	{
		bit = hour << 6;
		if (bit.count() > num) continue;
		for (int miniute = 0;miniute != 60;++miniute)
		{
			bit = (hour << 6) | miniute;
			if (bit.count() != num) continue;
			else
			{
				string tmp = to_string(hour) + ":";
				if (miniute < 10) tmp = tmp + "0" + to_string(miniute);
				else tmp += to_string(miniute);
				ans.push_back(tmp);
			}
		}
	}
	return ans;
}