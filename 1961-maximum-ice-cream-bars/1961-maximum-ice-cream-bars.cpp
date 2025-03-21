class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0, sum=0;
        for (int i=0; i!=costs.size(); i++)
        {
            sum=sum+costs[i];
            if (coins>=sum) ans++;
            else break;
        }
        return ans;
    }
};