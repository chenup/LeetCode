#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

/*
struct Node{
	int value;
	char letter;
	Node *left, *middle, *right;
	Node(char c) : value(-1), letter(c), left(NULL), middle(NULL), right(NULL) {}
}; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Node *root = buildTriTee(wordDict);
        if(s.size() == 0)
        {
        	return true;
        }
        bool flag = helper(root, root, s, 0);
        return flag;
    }

    bool helper(Node *tree, Node *root, string s, int d)
    {
    	if(root == NULL)
    	{
    		return helper(tree, tree, s, d);
    	}
    	char c = s[d];
    	if(c == root->letter)
    	{
    		if(d == s.size() - 1)
    		{
    			return root->value != -1;
    		}
    		else
    		{
    			if(helper(tree, root->middle, s, d + 1))
    			{
    				return true;
    			}
    			else
    			{
    				if(root->value != -1)
    				{
    					if()
    					{
    						return helper(tree, tree, s, d + 1);
    					}
    					else
    					{
    						return false;
    					}
    				}
    				else
    				{
    					return false;
    				}
    			}
    		}
    	}
    	else if(c < root->letter && c == root->left->letter)
    	{
    		return helper(tree, root->left, s, d);
    	}
    	else if(c > root->letter && c == root->right->letter)
    	{
    		return helper(tree, root->right, s, d);
    	}
    	return false;
    }

    Node* buildTriTee(vector<string>& wordDict)
    {
    	Node *root = NULL;
    	int count = 0;
    	for(auto it : wordDict)
    	{
    		root = put(root, it, count++, 0);
    	}
    	return root;
    }

    Node* put(Node *root, string key, int value, int d)
    {
    	char c = key[d];
    	if(root == NULL)
    	{
    		root = new Node(c);
    	}
    	if(c < root->letter)
    	{
    		root->left = put(root->left, key, value, d);
    	}
    	else if(c > root->letter)
    	{
    		root->right = put(root->right, key, value, d);
    	}
    	else if(d < key.size() - 1)
    	{
    		root->middle = put(root->middle, key, value, d + 1);
    	}
    	else
    	{
    		root->value = value;
    	}
    	return root;
    }
};
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {	
    	unordered_set<string> wd;
    	for(auto it : wordDict)
    	{
    		wd.insert(it);
    	}
    	vector<int> tmp(s.size(), -1);
    	if(s.size() == 0)
    	{
    		return true;
    	}
    	return isMatch(wd, tmp, s, 0);
    }

    bool isMatch(unordered_set<string>& wd, vector<int>& tmp, string s, int d)
    {
    	if(wd.find(s) != wd.end())
    	{
    		return true;
    	}
    	
    	for(int i = 1; i < s.size(); i++)
    	{
    		string str = s.substr(0, i);
    		if(wd.find(str) != wd.end())
    		{
    			bool isWordR;
    			if(tmp[i + d - 1] != -1)
    			{
    				isWordR = tmp[i + d - 1];
    			}
    			else
    			{
    				isWordR = isMatch(wd, tmp, s.substr(i, s.size() - i), d + i);
    				tmp[i + d - 1] = isWordR;
    			}
    			if(isWordR)
    			{
    				return true;
    			}
    		}	
    	}
    	return false;
    } 
};

int main(int argc, char const *argv[])
{
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	bool flag = Solution().wordBreak(s, wordDict);
	cout << flag << endl;
	return 0;
}