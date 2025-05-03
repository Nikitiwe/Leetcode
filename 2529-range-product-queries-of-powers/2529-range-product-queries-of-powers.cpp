class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> arr(1, 0);
        int mn = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                arr.push_back(mn);
                arr.back() += arr[arr.size()-2];
            }
            n /= 2;
            mn++;
        }
        vector<int> ans(q.size(), 1);
        for (int i=0; i!=q.size(); i++)
        {
            int t = arr[q[i][1]+1] - arr[q[i][0]];
            for (int j=0; j<t; j++)
            {
                ans[i] *= 2;
                ans[i] %= 1000000007;
            }
        }
        return ans;
    }
};