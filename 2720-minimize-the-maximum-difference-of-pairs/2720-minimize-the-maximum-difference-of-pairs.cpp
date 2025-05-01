class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        vector<int> d(nums.size(), 2000000000);
        for (int i=1; i<nums.size(); i++)
        {
            d[i-1] = nums[i] - nums[i-1];
        }
        int l = 0, r = 1000000001, m, ans = r;
        while (l <= r)
        {
            m = (l+r)/2;
            int c = 0, t = 0;
            for (int i=0; i<d.size(); i++)
            {
                if (d[i] <= m) t++;
                else
                {
                    c += (t+1)/2;
                    t = 0;
                }
            }
            c += (t+1)/2;
            if (c >= p)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};