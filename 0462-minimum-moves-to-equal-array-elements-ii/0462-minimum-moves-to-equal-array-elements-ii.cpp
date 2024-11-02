class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long> arr(nums.size()+1, 0);
        long sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            arr[i+1]=sum;
        }
        long ans=accumulate(nums.begin(), nums.end(), 0)-nums[0]*nums.size();
        for (int i=1; i<nums.size(); i++)
        {
            long t=(long)nums[i]*i-arr[i]+arr[arr.size()-1]-arr[i]-(long)(nums.size()-i)*nums[i];
            ans=min(ans, t);
        }
        return ans;
    }
};