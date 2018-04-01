class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> pos(m, 0);
        vector<int> res(1, 1);
        vector<int> tmp(m, 1);
        while(res.size() < n)
        {
        	int min = -1;
 			for(int i = 0; i < pos.size(); i++)
        	{
        		tmp[i] = res[pos[i]] * primes[i];
        		if(min == -1)
        		{
        			min = tmp[i];
        		}
        		else if(min > tmp[i])
        		{
        			min = tmp[i];
        		}
        	}
        	res.push_back(min);
        	for(int i = 0; i < pos.size(); i++)
        	{
        		if(min == tmp[i])
        		{
        			pos[i]++;
        		}
        	}
        }
        return res[n - 1];
    }
};