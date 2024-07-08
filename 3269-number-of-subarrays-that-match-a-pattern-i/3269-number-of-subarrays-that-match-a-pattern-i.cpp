class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans=0, isit;
        for (int i=0; i!=nums.size()-pattern.size(); i++)
        {
            isit=1;
            for (int j=0; j!=pattern.size(); j++)
            {
                if (pattern[j]==1) {if (nums[i+j]>=nums[i+j+1]) {isit=0; break;}}
                else if (pattern[j]==0) {if (nums[i+j]!=nums[i+j+1]) {isit=0; break;}}
                else if (pattern[j]==-1) {if (nums[i+j]<=nums[i+j+1]) {isit=0; break;}}
            }
            if (isit) ans++;
        }
        return ans;
    }
};