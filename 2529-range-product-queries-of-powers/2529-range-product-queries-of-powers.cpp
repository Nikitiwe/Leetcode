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
            long long mn = 2;
            long long res = 1;
            while (t > 0)
            {
                if (t % 2 == 1)
                {
                    res *= mn;
                    res %= 1000000007;
                }
                t /= 2;
                mn *= mn;
                mn %= 1000000007;
            }
            ans[i] = res;
        }
        return ans;
    }
};