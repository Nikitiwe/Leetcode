class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]=i;
        }
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(target-nums[i])>0&&i!=m[target-nums[i]]) return {i, m[target-nums[i]]};
        }
        return {0, 0};
    }
};