class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }
    
private:
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
/*
struct TrieNode
{
    char c;
    TrieNode *left, *mid, *right;
    int val;
    TrieNode(): left(NULL), mid(NULL), right(NULL), val(0), c('a') {}
};

class WordDictionary {
public:
    WordDictionary() {
        root = NULL;
        val = 1;
    }
    
     TrieNode* put(TrieNode* x, string word, int d)
    {
        char c = word[d];
        if(x == NULL)
        {
            x = new TrieNode();
            x->c = c;
        }
        if(c < x->c)
        {
            x->left = put(x->left, word, d);
        }
        else if(c > x->c)
        {
            x->right = put(x->right, word, d);
        }
        else if(d < word.size() - 1)
        {
            x->mid = put(x->mid, word, d + 1);
        }
        else
        {
            x->val = val++;
        }
        return x;
    }

    void addWord(string word) {
        root = put(root, word, 0);
    }
    
    bool search(string word) {
         if(!word.size())
        {
            return true;
        }
        TrieNode* res = get(root, word, 0);
        if(res)
        {
            if(res->val)
            {
                return true;
            }
        }
        return false;
    }

    TrieNode* get(TrieNode* x, string word, int d)
    {
        if(x == NULL) 
        {
            return NULL;
        }
        char c = word[d];
        if(c == '.')
        {
        	if(d < word.size() - 1)
        	{
        		TrieNode* tmp;
        		tmp = get(x->mid, word, d + 1);
        		if(tmp)
        		{
        			return tmp;
        		}
        		tmp = get(x->left, word, d);
        		if(tmp)
        		{
        			return tmp;
        		}
        		tmp = get(x->right, word, d);
        		if(tmp)
        		{
        			return tmp;
        		}
        		return NULL;
        	}
        	else if(d == word.size() - 1 && x->val)
        	{
        		return x;
        	}
        	else
        	{
        		TrieNode* tmp;
        		tmp = get(x->left, word, d);
        		if(tmp)
        		{
        			return tmp;
        		}
        		tmp = get(x->right, word, d);
        		if(tmp)
        		{
        			return tmp;
        		}
        		return NULL;
        	}
       	}
        else if(c < x->c)
        {
            return get(x->left, word, d);
        }
        else if(c > x->c)
        {
            return get(x->right, word, d);
        }
        else if(d < word.size() - 1)
        {
            return get(x->mid, word, d + 1);
        }
        else
        {
            return x;
        }
    }
private:
	TrieNode* root;
	int val;
};
*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */