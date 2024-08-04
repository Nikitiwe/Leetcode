class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> lsum(nums.size()+1, 0);
        int ans=0;
        long long sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            lsum[i+1]=lsum[i]+nums[i];
        }
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (lsum[i+1]>=sum-lsum[i+1]) ans++;
        }
        return ans;
    }
};