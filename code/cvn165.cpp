class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int len1 = v1.size();
        int len2 = v2.size();
        int i = 0;
        while(1)
        {
        	if(!(len1 || len2))
        	{
        		return 0;
        	}
        	else if(!len1 && len2)
        	{
        		if(!v2[i])
        		{
        			len2--;
        			i++;
        			continue;
        		}
        		else
        		{
        			return -1;
        		}
        		
        	}
        	else if(len1 && !len2)
        	{
        		if(!v1[i])
        		{
        			len1--;
        			i++;
        			continue;
        		}
        		else
        		{
        			return 1;
        		}
        	}
        	else
        	{
        		if(v1[i] > v2[i])
        		{
        			return 1;
        		}
        		else if(v1[i] < v2[i])
        		{
        			return -1;
        		}
        	}
        	len1--;
        	len2--;
        	i++;
        }
    }

    vector<int> split(string v)
    {
    	vector<int> res;
    	int n = 0;
    	int i = 0;
    	while(i < v.size())
    	{
    		if(v[i] == '.')
    		{
    			res.push_back(n);
    			n = 0;
    		}
    		else
    		{
    			n = n * 10 + v[i] - 48;
    		}
    		if(i == v.size() - 1)
    		{
    			res.push_back(n);
    		}
    		i++;
    	}
    	return res;
    }
};