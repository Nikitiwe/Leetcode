class Solution {
public:
    int longestWPI(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i!=nums.size(); i++) if (nums[i] > 8) sum++;
        int ans = 0, l = 0, r = min(2*sum - 1, (int)nums.size()), m;
        while (l <= r)
        {
            m = r;
            bool isit = 0;
            int a = 0, b = 0;
            for (int i=0; i<m; i++)
            {
                if (nums[i] > 8) a++;
                else b++;
            }
            if (a > b)
            {
                isit = 1;
            }
            else for (int i=m; i<nums.size(); i++)
            {
                if (nums[i] > 8) a++;
                else b++;
                if (nums[i-m] > 8) a--;
                else b--;
                if (a > b)
                {
                    isit = 1;
                    break;
                }
            }
            if (isit == 1)
            {
                ans = max(ans, m);
                break;
            }
            r = m-1;
        }
        return ans;
    }
};