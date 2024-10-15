class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<(int)nums.size()-1; i++)
        {
            if (nums[i]!=i+1) return 0;
        }
        if (nums[nums.size()-1]!=nums.size()-1) return 0;
        return 1;
    }
};