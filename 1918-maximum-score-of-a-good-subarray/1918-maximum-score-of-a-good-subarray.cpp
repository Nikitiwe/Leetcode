class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        for (int i=k+1; i<nums.size(); i++) nums[i] = min(nums[i], nums[i-1]);
        for (int i=k-1; i>=0; i--) nums[i] = min(nums[i], nums[i+1]);
        int ans = 0;
        int l = 0, r = nums.size()-1;
        while (l <= k && k <= r)
        {
            ans = max(ans, (r-l+1)*min(nums[l], nums[r]));
            if (nums[l] < nums[r]) l++;
            else r--;
        }
        return ans;
    }
};