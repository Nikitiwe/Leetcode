class Solution {
public:
    int fillCups(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int ans=nums[0], t=nums[1]+nums[2]-nums[0];
        if (t>0)
        {
            ans+=t/2;
            if (t%2==1) ans++;
        }
        return ans;
    }
};