class Solution {
public:
    long long maxRunTime(int n, vector<int>& nums) {
        long long ans = 0, l = 0, r = 100000000000000, m;
        while (l <= r)
        {
            m = (l+r)/2;
            long long sum = 0;
            for (int i=0; i!=nums.size(); i++) sum += min((long long)nums[i], m);
            if (sum >= m * n)
            {
                ans = max(ans, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};