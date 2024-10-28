class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> m;
        for (int i=1; i<nums.size(); i++)
        {
            m.insert(nums[i]+nums[i-1]);
            if (m.size()<i) return 1;
        }
        return 0;
    }
};