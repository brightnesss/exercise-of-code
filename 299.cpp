/*
 *	299. Bulls and Cows
 *	You are playing the following Bulls and Cows game with your friend: 
 	You write down a number and ask your friend to guess what the number is. 
 	Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess 
 	match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret 
 	number but locate in the wrong position (called "cows"). 
 	Your friend will use successive guesses and hints to eventually derive the secret number.

 *	For example:
	Secret number:  "1807"
	Friend's guess: "7810"
	Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
	Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

 *	Please note that both secret number and friend's guess may contain duplicate digits, for example:
	Secret number:  "1123"
	Friend's guess: "0111"
	In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
	You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
 */

/*
 *	先找到总共猜对了几个数字totalget
 *	再找完全匹配(位置和数字)上的match
 *	则答案就是matchA(totalget-match)B
 */
string getHint(string secret, string guess)
{
	map<char, int> m;
	for (char c : secret) ++m[c];
	int totalget(0);
	for (char c : guess)
	{
		if (m.find(c) == m.end()) continue;
		else
		{
			if (m[c] > 0)
			{
				++totalget;
				--m[c];
			}
			else continue;
		}
	}
	int match(0);
	int len(min(secret.size(), guess.size()));
	for (int i = 0;i != len;++i)
	{
		if (secret[i] == guess[i]) ++match;
		else continue;
	}
	string ans("");
	ans += to_string(match);
	ans += 'A';
	ans += to_string(totalget - match);
	ans += 'B';
	return ans;
}