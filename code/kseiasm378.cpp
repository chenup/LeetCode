/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
     	for(int i = 0; i < m; i++)
     	{
     		for(int j = 0; j < n; j++)
     		{
     			if(count < k)
        		{
        			q.push(matrix[i][j]);
        			count++;
        		}
        		else
        		{
        			if(q.top() > matrix[i][j])
        			{
        				q.pop();
        				q.push(matrix[i][j]);
        			}
        		}
     		}
     	}
     	return q.top();
    }
};
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int left = matrix[0][0];
    	int right = matrix.back().back();
    	while(left < right)
    	{
    		int mid = (left + right) / 2;
    		int cnt = helper(matrix, mid);
    		if(cnt < k)
    		{
    			left = mid + 1;
    		}
    		else
    		{
    			right = mid;
    		}
    	}
    	return left;
    }

    int helper(vector<vector<int>>& matrix, int mid)
    {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	int i = m - 1;
    	int j = 0;
    	int sum = 0;
    	while(i >= 0 && j < n)
    	{
    		if(mid >= matrix[i][j])
    		{
    			sum += i + 1;
    			j++;
    		}
    		else
    		{
    			i--;
    		}
    	}
    	return sum;

    }
};