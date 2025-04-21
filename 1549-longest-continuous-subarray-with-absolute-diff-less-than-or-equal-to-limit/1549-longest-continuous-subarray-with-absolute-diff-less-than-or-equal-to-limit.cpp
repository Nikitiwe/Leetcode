class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 1, l = 1, r = nums.size(), m;
        while (l <= r)
        {
            m = (l+r)/2;
            map<int, int> s;
            for (int i=0; i<m; i++)
            {
                s[nums[i]]++;
            }
            bool isit = 0;
            int mi = (s.begin())->first;
            int ma = (--s.end())->first;
            if (ma - mi <= k)
            {
                isit = 1;
            }
            if (isit == 0) for (int i=m; i<nums.size(); i++)
            {
                s[nums[i]]++;
                s[nums[i-m]]--;
                if (s[nums[i-m]] == 0) s.erase(nums[i-m]);
                int mi = (s.begin())->first;
                int ma = (--s.end())->first;
                if (ma - mi <= k)
                {
                    isit = 1;
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