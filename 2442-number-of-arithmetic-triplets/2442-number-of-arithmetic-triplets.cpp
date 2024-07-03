class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        for (int i=0; i!=nums.size()-2; i++)
        {
            if (find(nums.begin(), nums.end(), nums[i]+diff)!=nums.end())
            if (find(nums.begin(), nums.end(), nums[i]+2*diff)!=nums.end())
            ans++;
        }
        return ans;
    }
};