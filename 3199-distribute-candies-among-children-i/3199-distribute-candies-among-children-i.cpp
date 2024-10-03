class Solution {
public:
    int distributeCandies(int n, int l) {
        int ans=0;
        for (int i=0; i<=l; i++)
        {
            for (int j=0; j<=l; j++)
            {
                if (n-i-j<=l&&n-i-j>=0) ans++;
            }
        }
        return ans;
    }
};