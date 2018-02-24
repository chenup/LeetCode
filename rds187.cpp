#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        map<int,int> table;
        int count = 1;
        int seq = 0;
        for(auto it : s)
        {
        	int n = c2i(it);
        	if(count < 10)
        	{
        		seq = (seq << 2) | n;
        		count++;
        		continue;
        	}
        	else if(count == 10)
        	{
        		seq = (seq << 2) | n;
        		//cout << seq2str(seq) << endl;
        		count++;
        	}
        	else if(count == 11)
        	{
        		seq = ((seq & 0x3ffff) << 2) | n;
        		//cout << seq2str(seq) << endl;
        	}
        	if(table.find(seq) != table.end())
    		{
    			//cout << seq << endl;
    			if(table[seq] == 1)
    			{
    				string s = seq2str(seq);
    				res.push_back(s);
    				table[seq]++;
    			}
    		}
    		else
    		{
    			table[seq] = 1;	
    		}
        }
        return res;
    }

    int c2i(char c)
    {
    	int tmp;
    	switch(c)
    	{
    		case 'A':
    		{
    			tmp = 0;
    		}
    		break;
    		case 'C':
    		{
    			tmp = 1;
    		}
    		break;
    		case 'G':
    		{
    			tmp = 2;
    		}
    		break;
    		case 'T':
    		{
    			tmp = 3;
    		}
    		break;
    		default:
    		break;
    	}
    	return tmp;
    }

    int i2c(int n)
    {
    	char tmp;
    	switch(n)
    	{
    		case 0:
    		{
    			tmp = 'A';
    		}
    		break;
    		case 1:
    		{
    			tmp = 'C';
    		}
    		break;
    		case 2:
    		{
    			tmp = 'G';
    		}
    		break;
    		case 3:
    		{
    			tmp = 'T';
    		}
    		break;
    		default:
    		break;
    	}
    	return tmp;
    }
    string seq2str(int seq)
	{
		string s = "";
		for(int i = 1; i <= 10; i++)
		{
			int k = seq & 0x3;
			seq = seq >> 2;
			char c = i2c(k);
			s = c + s;
		}
		return s;
	}

};


int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> res = Solution().findRepeatedDnaSequences(s);
	for(auto it : res)
	{
		cout << it << endl;
	}
	return 0;
}