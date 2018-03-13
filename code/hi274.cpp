class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
        {
        	return 0;
        }
        sort(citations.begin(), citations.end(), greater<int>());
        int i;
        for(i = 0; i < citations.size(); i++)
        {
        	if((i + 1) > citations[i])
        	{
        		break;
        	}
        }
        return i;
    }
};