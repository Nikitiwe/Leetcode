class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 1;
        map<int, int> s;
        int l = 0;
        for (int i=0; i<nums.size(); i++)
        {
            s[nums[i]]++;
            int mi = (s.begin())->first;
            int ma = (--s.end())->first;
            if (ma - mi <= k)
            {
                ans = max(ans, i - l + 1);
            }
            else
            {
                while (ma - mi > k)
                {
                    s[nums[l]]--;
                    if (s[nums[l]] == 0) s.erase(nums[l]);
                    l++;
                    mi = (s.begin())->first;
                    ma = (--s.end())->first;
                }
            }
        }
        return ans;
    }
};