/*
 *	127. Word Ladder
 *	Given two words (beginWord and endWord), and a dictionary's word list, 
 *	find the length of shortest transformation sequence from beginWord to endWord, such that:

 *	Only one letter can be changed at a time.
 *	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *	For example,

 *	Given:
 *	beginWord = "hit"
 *	endWord = "cog"
 *	wordList = ["hot","dot","dog","lot","log","cog"]
 *	As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *	return its length 5.

 *	Note:
 *	Return 0 if there is no such transformation sequence.
 *	All words have the same length.
 *	All words contain only lowercase alphabetic characters.
 *	You may assume no duplicates in the word list.
 *	You may assume beginWord and endWord are non-empty and are not the same.
 */

/*
 *	广度优先搜索
 *	Well, this problem has a nice BFS structure.
 *	Let's see the example in the problem statement.
 *	start = "hit"
 *	end = "cog"
 *	dict = ["hot", "dot", "dog", "lot", "log"]
 *	Since only one letter can be changed at a time, if we start from "hit", 
 *	we can only change to those words which have only one different letter from it, like "hot". 
 *	Putting in graph-theoretic terms, we can say that "hot" is a neighbor of "hit".

 *	The idea is simpy to begin from start, then visit its neighbors, 
 *	then the non-visited neighbors of its neighbors... Well, this is just the typical BFS structure.

 *	To simplify the problem, we insert end into dict. 
 *	Once we meet end during the BFS, we know we have found the answer. 
 *	We maintain a variable dist for the current distance of the transformation and update it by dist++ after we finish a round of BFS search
 *	(note that it should fit the definition of the distance in the problem statement). 
 *	Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
 */

void subLadderLength(string word, unordered_set<string>& wordList, queue<string>& to_visit)
{
	//wordList存储的是还未被遍历到的点
	char letter;
	wordList.erase(word);	
	for (int i = 0;i != word.size();++i)
	{
		letter = word[i];
		for (int j = 0;j != 26;++j)
		{
			word[i] = 'a' + j;
			if (wordList.find(word)!=wordList.end()) //找到了
			{
				//若是邻接点,压入to_visit,同时从未遍历点的集合wordList中删除
				to_visit.push(word);
				wordList.erase(word);
			}
		}
		word[i] = letter;
	}
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	queue<string> to_visit;	//用来存储下一层需要遍历的结点
	unordered_set<string> list(wordList.begin(), wordList.end());	//使用unordered_set能极大加快速度
	to_visit.push(beginWord);	//先将开始的压入
	int distance(1);	//距离为1
	string word;
	int len(to_visit.size());	//这一层的节点数
	while (!to_visit.empty())
	{
		for (int i = 0;i != len;++i)
		{
			//先将这一层的结点遍历完才能遍历下一层,即要符合BFS的特征
			word = to_visit.front();	//下一个该遍历的结点
			to_visit.pop();
			if (word == endWord) return distance;	//若这个点就是终点了,就可以直接返回这一层的距离distance
			else
			{
				subLadderLength(word, list, to_visit);	//寻找这个点的邻接点
			}
		}//这一层已经遍历结束了
		++distance;	//层数+1
		len = to_visit.size();	//新的一层的节点个数
	}//若进行到此都没有返回,说明没有能够从beginWord到endWord
	return 0;
}