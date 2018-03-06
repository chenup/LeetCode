class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 1; i <= 32; i++)
        {
        	res = res << 1;
        	if(n & 0x1)
        	{
        		n = n >> 1;
        		res |= 1;
        		
        	}
        	else
        	{
        		n = n >> 1;
        	}
        }
        return res;
    }
};