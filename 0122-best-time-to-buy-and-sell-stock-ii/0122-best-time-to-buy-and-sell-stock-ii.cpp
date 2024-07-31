class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, temp;
        for (int i=0; i!=prices.size()-1; i++)
        {
            temp=prices[i+1]-prices[i];
            if (temp>0) ans+=temp;
        }
        return ans;
    }
};