class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        if (find(nums.begin(), nums.end(), 0)==nums.end()) return 0;
        for (int i=distance(nums.begin(), find(nums.begin(), nums.end(), 0))+1; i!=nums.size(); i++)
        {
            if (nums[i]!=nums[i-1]) ans++;
        }
        return ans+1;
    }
};