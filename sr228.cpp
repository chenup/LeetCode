class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
        {
        	return res;
        }
        auto start = nums.begin();
        vector<int>::iterator end;
        for(end = nums.begin(); end != nums.end(); end++)
        {
        	if(*end - *start == end - start)
        	{
        		continue;
        	}
        	else
        	{
        		if(end - start == 1)
        		{
        			res.push_back(to_string(*start));
        		}
        		else
        		{
        			string tmp = to_string(*start) + "->" + to_string(*(end - 1));
        			res.push_back(tmp);
        		}
        		start = end;
        	}
        }
        if(end - start == 1)
        {
        	res.push_back(to_string(*start));
        }
        else
        {
        	string tmp = to_string(*start) + "->" + to_string(*(end - 1));
        	res.push_back(tmp);
        }
        return res;
    }
};