class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int ls=0, rs=0;
        vector<int> ans;
        for (int i=0; i!=nums.size(); i++)
        {rs=rs+nums[i];}
        rs=rs-nums[0];
        ans.push_back(abs(rs));
        for (int i=1; i!=nums.size(); i++)
        {
            rs=rs-nums[i];
            ls=ls+nums[i-1];
            ans.push_back(abs(rs-ls));
        }
        return ans;
    }
};