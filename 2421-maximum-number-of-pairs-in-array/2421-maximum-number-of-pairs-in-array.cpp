class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l=0, ans=0;
        while (l<nums.size()-1)
        {
            if (nums[l]==nums[l+1])
            {
                ans++;
                l+=2;
            }
            else l++;
        }
        return {ans, (int)nums.size()-ans*2};
    }
};