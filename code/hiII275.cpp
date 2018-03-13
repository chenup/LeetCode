class Solution {
public:
    int hIndex(vector<int>& citations) {
  		int n = citations.size();
  		if(n == 0)
  		{
  			return 0;
  		}
  		int i;
  		for(i = n - 1; i >= 0; i--)
  		{
  			if(citations[i] < n - i)
  			{
  				break;
  			}
  		}
  		return n - i - 1;      
    }
};