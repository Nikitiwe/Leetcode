class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& nums) {
        long long l = 0, r = 1e16, m, ans = r;
        while (l <= r)
        {
            m = (l+r)/2;
            long long h = 0;
            for (int i=0; i!=nums.size(); i++)
            {
                long long c = (sqrt(m*8/nums[i] + 1) - 1) / 2;
                h += c;
            }
            if (h >= mountainHeight)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};