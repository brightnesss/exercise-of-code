/*
 *	208. Implement Trie (Prefix Tree)
 *	Implement a trie with insert, search, and startsWith methods.

 *	Note:
 *	You may assume that all inputs are consist of lowercase letters a-z.
 */

/*
 *	字典树,即按照字符串的顺序从头到尾生长的一颗树
 */

class Trie {
private:
    struct dict	//字典树的数据结构
    {
        bool is_string;	//表示以此结尾是不是一个完整的字符串
        vector<dict*> next;	//往后继续的字符表
        dict(bool b=false)
        {
            is_string=b;
            next=vector<dict*>(26,NULL);	//因为仅仅含有小写字母a-z,所以我们可以用一个大小为26的数组表示
        }
    };
    
    dict *root;	//根结点
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new dict();	//初始化生成根
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 	//插入一个string到树中
    {
        dict *tmp=root;
        for (int i=0;i!=word.size();++i)
        {
            if (tmp->next[word[i]-'a']==NULL) tmp->next[word[i]-'a']=new dict();	//如果这个字符是新字符,则新new一个,word[i]-'a'就可以知道它是那个字符(按字母顺序排列)
            tmp=tmp->next[word[i]-'a'];	//深度遍历
        }
        tmp->is_string=true;	//因为这个string已经遍历完了,所以这个结点的is_string=true,即表示到这里是一个完整的string
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {	//搜索
        dict *tmp=root;
        for (int i=0;i!=word.size();++i)
        {
            if (tmp->next[word[i]-'a']==NULL) return false;	//若就没有这个字符,肯定不存在这个string
            tmp=tmp->next[word[i]-'a'];
        }
        return tmp->is_string;	//遍历结束了,但是不是一个完整的string还有看is_string
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {	//和搜索类似
        dict *tmp=root;
        for (int i=0;i!=prefix.size();++i)
        {
            if (tmp->next[prefix[i]-'a']==NULL) return false;
            tmp=tmp->next[prefix[i]-'a'];
        }
        return true;	//不需要看是不是一个完整的字符,只要以prefix开头就好了
    }
};