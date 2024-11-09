class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i=n/2; i<n; i++)
        {
            int a=i, b=n-i, s=1;
            while (a>0)
            {
                s*=a%10;
                a/=10;
            }
            while (b>0)
            {
                s*=b%10;
                b/=10;
            }
            if (s>0) return {i, n-i};
        }
        return {-1, -1};
    }
};