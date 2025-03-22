class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1000000, m, ans = 0, mans = 1000000;
        while (l <= r)
        {
            m = (l+r)/2;
            int count = 0, a = 0;
            for (int i = 0; i!=nums.size(); i++)
            {
                while (a+1 < nums.size() && nums[a+1] <= nums[i] + m) a++;
                count += a-i;
            }
            if (count >= k)
            {
                r = m-1;
                mans = min(mans, m);
            }
            else
            {
                l = m+1;
                ans = max(ans, m);
            }
        }
        return mans;
    }
};