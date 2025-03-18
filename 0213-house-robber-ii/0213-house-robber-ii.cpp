class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        int ans = 0;
        // сначала первый не участвует
        {
            vector<int> lp(nums.size(), 0), lf = lp;
            lp[1] = nums[1];
            for (int i=2; i<nums.size(); i++)
            {
                lp[i] = nums[i] + max(lp[i-2], lf[i-1]);
                lf[i] = max(lp[i-2], lp[i-1]);
            }
            ans = max(lp[nums.size()-1], lf[nums.size()-1]);
        }
        // теперь первый участвует
        {
            vector<int> lp(nums.size()-1, 0), lf = lp;
            lp[0] = nums[0];
            lp[1] = nums[1];
            lf[1] = nums[0];
            for (int i=2; i<lp.size(); i++)
            {
                lp[i] = nums[i] + max(lp[i-2], lf[i-1]);
                lf[i] = max(lp[i-2], lp[i-1]);
            }
            ans = max(ans, lf[lp.size()-1]);
            ans = max(lp[lp.size()-1], ans);
        }
        return ans;
    }
};