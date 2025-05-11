class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int l = 1, r = nums.size(), m, ans = 1;
        while (l <= r)
        {
            m = (l+r)/2;
            int d = min(m, (int)nums.size());
            unordered_map<int, int> s;
            bool isit = 0;
            for (int i=0; i<d; i++)
            {
                s[nums[i]]++;
                if (s[nums[i]] + k >= m)
                {
                    ans = max(ans, s[nums[i]]);
                    isit = 1;
                    //break;
                }
            }
            for (int i=d; i<nums.size(); i++)
            {
                s[nums[i-d]]--;
                s[nums[i]]++;
                if (s[nums[i]] + k >= m)
                {
                    ans = max(ans, s[nums[i]]);
                    isit = 1;
                    //break;
                }
            }
            if (isit == 1)
            {
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};