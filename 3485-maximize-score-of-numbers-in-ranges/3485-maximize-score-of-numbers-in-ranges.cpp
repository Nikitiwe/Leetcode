class Solution {
public:
    int maxPossibleScore(vector<int>& nums, int d) {
        long ans = 0;
        sort(nums.begin(), nums.end());
        long l = 0, r = (nums.back() + d - nums[0]) / (nums.size() - 1), m;
        while (l <= r)
        {
            m = (l+r)/2;
            long prev = nums[0];
            bool isit = 1;
            for (int i=1; i<nums.size(); i++)
            {
                if (prev + m <= nums[i] + d)
                {
                    prev = max(prev + m, (long)nums[i]);
                }
                else
                {
                    isit = 0;
                    break;
                }
            }
            if (isit == 1)
            {
                ans = max(ans, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};