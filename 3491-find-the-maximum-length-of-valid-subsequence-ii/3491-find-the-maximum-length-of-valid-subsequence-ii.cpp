class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        for (int i=0; i!=nums.size(); i++) nums[i]%=k;
        vector<vector<int>> arr(nums.size(), vector<int> (k, 1));
        int ans=1;
        for (int i=1; i<nums.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                arr[i][nums[j]]=arr[j][nums[i]]+1;
                ans=max(ans, arr[i][nums[j]]);
            }
        }
        return ans;
    }
};