class Solution {
public:
    long long maxSum(vector<vector<int>>& g, vector<int>& l, int k) {
        long long ans = 0;
        priority_queue<int> arr;
        for (int i=0; i!=g.size(); i++)
        {
            sort(g[i].rbegin(), g[i].rend());
            for (int j=0; j<l[i]; j++) arr.push(g[i][j]);
        }
        for (int i=0; i!=k; i++)
        {
            ans += arr.top();
            arr.pop();
        }
        return ans;
    }
};