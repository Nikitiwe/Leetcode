class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i=0; i<nums.size(); i++)
        {
            int mi = nums[i], ma = nums[i];
            for (int j=i; j<nums.size(); j++)
            {
                mi = min(mi, nums[j]);
                ma = max(ma, nums[j]);
                ans += ma - mi;
            }
        }
        return ans;
    }
};