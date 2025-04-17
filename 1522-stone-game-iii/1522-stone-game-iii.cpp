class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.size(), 0);
        arr.back() = nums.back();
        if (n > 1) arr[n-2] = max(nums[n-2] + nums[n-1], nums[n-2] - nums[n-1]);
        if (n > 2) arr[n-3] = max({nums[n-3] + nums[n-2] + nums[n-1], nums[n-3] + nums[n-2] - nums[n-1], nums[n-3] - arr[n-2]});
        for (int i=n-4; i>=0; i--)
        {
            arr[i] = max({nums[i] + nums[i+1] + nums[i+2] - arr[i+3], nums[i] + nums[i+1] - arr[i+2], nums[i] - arr[i+1]});
        }
        if (arr[0] > 0) return "Alice";
        else if (arr[0] == 0) return "Tie";
        else return "Bob";
    }
};