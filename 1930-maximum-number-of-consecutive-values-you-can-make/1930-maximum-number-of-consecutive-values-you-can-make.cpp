class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans=0;
        if (coins[0]==1) ans++;
        else return 1;
        for (int i=1; i!=coins.size(); i++)
        {
            if (coins[i]<=ans+1) ans+=coins[i];
            else return ans+1;
        }
        return ans+1;
    }
};