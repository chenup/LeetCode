struct TrieNode
{
    TrieNode* pre;
    TrieNode* next;
    TrieNode* middle;
    char letter;
    int idx;
    TrieNode(char c, int n) : pre(NULL), middle(NULL), next(NULL), letter(c), idx(n) {}
};


/*
class Trie {
public:
    Trie() {
        root = NULL;
        count = 0;
    }
    
    void insert(string word) {
        if(!word.size())
        {
            return;
        }
        if(!root)
        {
            root = new TrieNode(word[0], -1);
        }
        int i = 0;
        TrieNode* p = root;
        while(i < word.size())
        {
            if(i == word.size() - 1)
            {
                p->idx = count++;
                return;
            }
            if(word[i] == p->letter)
            {
                if(p->middle)
                {
                    p = p->middle;
                    i++;
                }
                else
                {
                    p->middle = new TrieNode(word[i + 1], -1);
                    p = p->middle;
                    i++;
                }
            }
            else if(word[i] < p->letter)
            {
                if(p->pre)
                {
                    p = p->pre;
                }
                else
                {
                    p->pre = new TrieNode(word[i], -1);
                    p = p->pre;
                }
            }
            else if(word[i] > p->letter)
            {
                if(p->next)
                {
                    p = p->next;
                }
                else
                {
                    p->next = new TrieNode(word[i], -1);
                    p = p->next;
                }
            }
        }
    }
    

    bool search(string word) {
         if(!word.size())
        {
            return true;
        }
        if(!root)
        {
            return false;
        }
        else
        {
            TrieNode* p = root;
            int i = 0;
            while(i < word.size())
            {
                if(!p)
                {
                    return false;
                }
                if(word[i] == p->letter)
                {
                    if(i == word.size() - 1)
                    {
                        if(p->idx == -1)
                        {
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    p = p->middle;
                    i++;
                }
                else if(word[i] < p->letter)
                {
                    p = p->pre;
                }
                else if(word[i] > p->letter)
                {
                    p = p->next;
                }
            }
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        if(!prefix.size())
        {
            return true;
        }
        if(!root)
        {
            return false;
        }
        else
        {
            TrieNode* p = root;
            int i = 0;
            while(i < prefix.size())
            {
                if(!p)
                {
                    return false;
                }
                if(prefix[i] == p->letter)
                {
                    p = p->middle;
                    i++;
                }
                else if(prefix[i] < p->letter)
                {
                    p = p->pre;
                }
                else if(prefix[i] > p->letter)
                {
                    p = p->next;
                }
            }
            return true;
        }
    }
private:
    TrieNode* root;
    int count;
};
*/

struct TrieNode
{
    char c;
    TrieNode *left, *mid, *right;
    int val;
    TrieNode(): left(NULL), mid(NULL), right(NULL), val(0), c('a') {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = NULL;
        val = 1;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root = put(root, word, 0);
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
    
    /** Returns if the word is in the trie. */
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
        if(c < x->c)
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(!prefix.size())
        {
            return true;
        }
        TrieNode* res = get(root, prefix, 0);
        if(res)
        {
            return true;
        }
        return false;
    }

private:
    TrieNode* root;
    int val;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */