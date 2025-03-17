class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> s(nums.size()+1, 0);
        for (int i=0; i!=nums.size(); i++) s[i+1] = s[i] + nums[i];
        int ans = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            ans += (s[i+1] - s[max(0, i - nums[i])]);
        }
        return ans;
    }
};