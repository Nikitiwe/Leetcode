class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n=piles.size(), ans=0;
        for (int i=1; i<=n/3; i++)
        {
            ans=ans+piles[n-2*i];
        }
        return ans;
    }
};