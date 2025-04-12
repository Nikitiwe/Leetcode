class Solution {
public:
    vector<int> evenOddBit(int n) {
        int a = 0, b = 0, x = n & 2730, y = n & 1365;
        for (int i=0; i!=10; i++)
        {
            a += x%2;
            x/=2;
            b += y%2;
            y/=2;
        }
        return {b, a};
    }
};