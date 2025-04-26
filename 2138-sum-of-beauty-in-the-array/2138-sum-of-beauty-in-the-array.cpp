class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        int mi = nums[0];
        for (int i = 1; i+1 < nums.size(); i++)
        {
            if (nums[i] > mi) arr[i]++;
            mi = max(mi, nums[i]);
        }
        mi = nums.back();
        for (int i = nums.size()-2; i>=1; i--)
        {
            if (nums[i] < mi) arr[i]++;
            mi = min(mi, nums[i]);
        }
        int ans = 0;
        for (int i=1; i+1<nums.size(); i++)
        {
            if (arr[i] == 2) ans += 2;
            else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) ans++;
        }
        return ans;
    }
};