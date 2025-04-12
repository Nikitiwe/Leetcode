class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for (int i=0; i!=ans.size(); i++)
        {
            for (int j = 0; j<1001; j++)
            {
                if (((j+1) | j) == nums[i])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};