class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> m(nums.begin(), nums.end());
        if (nums[0]<k) return -1;
        else if (nums[0]==k) return m.size()-1;
        else return m.size();
    }
};