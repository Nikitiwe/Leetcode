class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l=0, r=0, ans=0;
        while (r<nums.size())
        {
            if (nums[r]==nums[l]) r++;
            else if (nums[r]>nums[l]) {r++; l++; ans++;}
        }
        return ans;
    }
};