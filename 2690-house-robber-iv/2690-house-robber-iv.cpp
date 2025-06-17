class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1, r=1e9, ans=1e9, m;
        while (l <= r)
        {
            m = (l+r)/2;
            int c = 0;
            for (int i=0; i<nums.size(); i++)
            {
                if (nums[i] <= m)
                {
                    c++;
                    i++;
                }
            }
            if (c >= k)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};