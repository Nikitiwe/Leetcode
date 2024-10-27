class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int r=0, l=0, n=nums.size();
        for (int i=1; i!=n; i++) r+=nums[i]-nums[0];
        vector<int> ans(n, 0);
        ans[0]=r;
        for (int i=1; i!=n; i++)
        {
            r-=(n-i)*(nums[i]-nums[i-1]);
            l+=(i)*(nums[i]-nums[i-1]);
            ans[i]=r+l;
        }
        return ans;
    }
};