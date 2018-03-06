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
            return false;
        }
        TrieNode* res = get(root, word, 0);
        if(res)
        {
            if(res->val)
            {
                res->val = 0;
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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> res;
        if (board.empty() || words.empty())
        {
            return res;
        }
        Trie *obj = new Trie();
        for(auto str : words)
        {
            obj->insert(str);
        }
        int rows = board.size();
        int cols = board[0].size();
        int len = 0;
        bool* visit = new bool[rows * cols];
        memset(visit, 0, rows * cols);
        for (int row = 0; row < rows;++row) 
        {
            for (int col = 0; col < cols;++col) 
            {
                string str = "";
                dfs(board, rows, cols, row, col, obj, str, visit, res);
                //memset(visit, 0, rows * cols);
            }
        }
        delete[] visit;
        return res;
    }

    void dfs(vector<vector<char>>& board, int rows, int cols, int row, int col, Trie* obj, string str, bool* visit, vector<string>& res) 
    {
        if(obj->search(str))
        {
            res.push_back(str);
        }
        if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols) && !visit[row*cols + col])
        {
            str = str + board[row][col];
            if(obj->startsWith(str))
            {
                visit[row*cols + col] = true;
                dfs(board, rows, cols, row - 1, col, obj, str, visit, res);
                dfs(board, rows, cols, row, col + 1, obj, str, visit, res);
                dfs(board, rows, cols, row + 1, col, obj, str, visit, res);
                dfs(board, rows, cols, row, col - 1, obj, str, visit, res);
                visit[row*cols + col] = false;
            }
        }
        return;
    }
};