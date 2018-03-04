class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (D - B) * (C - A) + (H - F) * (G - E);
        if(A >= G || C <= E || B >= H || F >= D)
        {
        	return sum;
        }
        return sum - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)); 
    }
};