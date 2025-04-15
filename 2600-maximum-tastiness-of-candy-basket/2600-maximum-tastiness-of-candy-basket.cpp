class Solution {
public:
    int maximumTastiness(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0, r = nums.back(), m;
        while (l <= r)
        {
            m = (l+r)/2;
            int t = nums[0], c = 1;
            for (int i=1; i<nums.size(); i++)
            {
                if (nums[i] >= t + m)
                {
                    t = nums[i];
                    c++;
                }
            }
            if (c >= k)
            {
                ans = max(ans, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};