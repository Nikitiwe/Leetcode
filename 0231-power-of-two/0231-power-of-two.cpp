class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n>=1)
        {
            while (n>1)
            {
                if (n%2==1) return 0;
                n/=2;
            }
            return 1;
        }
        else return 0;
    }
};