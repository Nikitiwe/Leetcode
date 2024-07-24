class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        if (nums[0]>0) ans++;
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (nums[i]==nums[i+1]) ;
            else if (i+1>nums[i]&&i+1<nums[i+1]) ans++;
        }
        if (nums[nums.size()-1]<nums.size()) ans++;
        return ans;
    }
};