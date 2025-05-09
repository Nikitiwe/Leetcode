class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        vector<long long> ans(q.size(), 0);
        sort(nums.begin(), nums.end());
        vector<long long> sum(nums.size()+1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            sum[i+1] = sum[i] + nums[i];
        }
        for (int i=0; i!=q.size(); i++)
        {
            long long l = 0, r = nums.size()-1, m;
            long long t = -1;
            while (l <= r)
            {
                m = (l+r)/2;
                if (nums[m] <= q[i])
                {
                    t = max(t, m);
                    l = m+1;
                }
                else r = m-1;
            }
            ans[i] = (t+1) * q[i] - sum[t+1] + sum.back() - sum[t+1] - ((long long)nums.size() - (t+1)) * q[i];
        }
        return ans;
    }
};