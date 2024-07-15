class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=1, temp=1;
        for (int i=1; i!=prices.size(); i++)
        {
            if (prices[i]==prices[i-1]-1) temp++;
            else temp=1;
            ans+=temp;
        }
        return ans;
    }
};