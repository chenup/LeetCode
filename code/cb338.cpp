class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int pos = 0;
        while(true)
        {
        	int i = 0;
        	while(i <= pos)
        	{
        		if(res.size() == num)
  				{
  					return res;
  				}
        		res.push_back(res[i++] + 1);
  				
        	}
        	pos = res.size() - 1;
        }
    }
};