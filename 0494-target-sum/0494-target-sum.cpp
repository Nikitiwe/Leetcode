class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> prev, next;
        prev[nums[0]]++;
        prev[-nums[0]]++;
        for (int i=1; i<nums.size(); i++)
        {
            for (auto it=prev.begin(); it!=prev.end(); it++)
            {
                next[it->first+nums[i]]+=it->second;
                next[it->first-nums[i]]+=it->second;
            }
            prev=next;
            next.clear();
        }
        return prev[target];
    }
};