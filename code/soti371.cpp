class Solution {
public:
    int getSum(int a, int b) {
        int num = a ^ b;
        int carry = (a & b) << 1;
        return carry == 0 ? num : getSum(num, carry);
    }
};