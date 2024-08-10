class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, 100000);
        ans[0]=0;
        for (long i=0; i<amount; i++)
        {
            for (long j=0; j<coins.size(); j++)
            {
                if (i+(long)coins[j]<=amount) ans[i+coins[j]]=min(ans[i]+1, ans[i+coins[j]]);
            }
        }
        if (ans[amount]!=100000) return ans[amount];
        else return -1;
    }
};