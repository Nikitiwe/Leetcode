class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        if (k*2>=nums.size()) return ans;
        long sum=0;
        for (int i=0; i<=2*k; i++) sum+=nums[i];
        ans[k]=sum/(2*k+1);
        for (int i=k+1; i<nums.size()-k; i++)
        {
            sum+=nums[i+k];
            sum-=nums[i-k-1];
            ans[i]=sum/(2*k+1);
        }
        return ans;
    }
};