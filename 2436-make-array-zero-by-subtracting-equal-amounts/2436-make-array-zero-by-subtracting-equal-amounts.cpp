class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> m;
        for (int i=0; i!=nums.size(); i++) if (nums[i]!=0) m.insert(nums[i]);
        return m.size();
    }
};