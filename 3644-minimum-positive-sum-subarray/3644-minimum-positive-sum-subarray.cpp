class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=10000000;
        for (int k=l; k<=r; k++)
        {
            int sum=0;
            for (int i=0; i!=k; i++) sum+=nums[i];
            if (sum>0) ans=min(ans, sum);
            for (int i=k; i<nums.size(); i++)
            {
                sum+=nums[i];
                sum-=nums[i-k];
                if (sum>0) ans=min(ans, sum);
            }
        }
        if (ans==10000000) return -1;
        else return ans;
    }
};