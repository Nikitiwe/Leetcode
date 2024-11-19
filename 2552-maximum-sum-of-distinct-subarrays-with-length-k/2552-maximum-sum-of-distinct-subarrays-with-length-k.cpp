class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> arr(100001, 0);
        long long sum=0, ans=0;
        int c=0;
        for (int i=0; i!=k; i++)
        {
            arr[nums[i]]++;
            if (arr[nums[i]]==2) c++;
            sum+=nums[i];
        }
        if (c==0) ans=max(ans, sum);
        for (int i=k; i<nums.size(); i++)
        {
            arr[nums[i]]++;
            if (arr[nums[i]]==2) c++;
            sum+=nums[i];
            arr[nums[i-k]]--;
            if (arr[nums[i-k]]==1) c--;
            sum-=nums[i-k];
            if (c==0) ans=max(ans, sum);
        }
        return ans;
    }
};