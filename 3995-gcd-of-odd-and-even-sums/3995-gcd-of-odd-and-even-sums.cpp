class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 0, b = 0;
        for (int i=1; i<n*2; i+=2)
        {
            a += i;
            b += i+1;
        }
        return gcd(a, b);
    }
};