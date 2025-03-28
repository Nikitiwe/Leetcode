class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int ans = 10000000, l = 1, r = 10000000, m;
        while (l <= r)
        {
            m = (l+r)/2;
            long sum = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                sum += ((long)nums[i]+m-1)/m;
            }
            if (sum <= t)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};