class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0, ans=-1000000000;
        for (int i=0; i<k-1; i++) sum+=nums[i];
        for (int i=k-1; i<nums.size(); i++)
        {
            sum+=nums[i];
            ans=max(ans, sum);
            sum-=nums[i-k+1];
        }
        return (double)ans/k;
    }
};