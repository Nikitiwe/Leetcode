class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans=0;
        long long sum=0, l=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
        }
        for (int i=0; i<nums.size()-1; i++)
        {
            l+=nums[i];
            sum-=nums[i];
            if (l>=sum) ans++;
        }
        return ans;
    }
};