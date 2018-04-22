class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for(int i = 0; i < b.size(); i++)
        {
        	res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }

   	int pow(int a, int b)
   	{
   		if(b == 0)
   		{
   			return 1;
   		}
   		if(b == 1)
   		{
   			return a % 1337;
   		}
   		return (pow(a, b / 2) % 1337) * (pow(a, b - b / 2) % 1337) % 1337; 
   	}
};