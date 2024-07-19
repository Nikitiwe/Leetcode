class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for (int i=0; i!=nums.size(); i++)
        {
            if (n.count(nums[i])>0) return 1;
            n.insert(nums[i]);
        }
        return 0;
    }
};