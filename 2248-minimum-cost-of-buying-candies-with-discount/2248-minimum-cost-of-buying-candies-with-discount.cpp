class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int ans = 0;
        for (int i=0; i!=nums.size(); i++) if (i%3 != 2) ans += nums[i];
        return ans;        
    }
};