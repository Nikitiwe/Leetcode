class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        int ans=nums[nums.size()-1];
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (i-k>=0) nums[i-k]+=nums[i];
            ans=max(ans, nums[i]);
        }
        return ans;
    }
};