class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<int>> arr(n+1);
        for (int i=0; i!=rides.size(); i++)
        {
            arr[rides[i][0]].push_back(rides[i][1]);
            arr[rides[i][0]].push_back(rides[i][1]-rides[i][0]+rides[i][2]);
        }
        vector<long long> ans(n+1, 0);
        long long temp=0;
        for (int i=1; i<=n; i++)
        {
            temp=max(temp, ans[i]);
            for (int j=0; j<arr[i].size(); j=j+2)
            {
                ans[arr[i][j]]=max(ans[arr[i][j]], temp+arr[i][j+1]);
            }
            ans[i]=temp;
        }
        return ans[n];
    }
};