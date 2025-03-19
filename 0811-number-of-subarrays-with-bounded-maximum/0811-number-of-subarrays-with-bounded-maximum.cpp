class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        int ans = 0, t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] <= r)
            {
                t++;
                ans += t;
            }
            else t = 0;
        }
        t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] > r)
            {
                t = 0;
            }
            else if (nums[i] < l)
            {
                t++;
                ans -= t;
            }
            else t = 0;
        }
        return ans;
    }
};