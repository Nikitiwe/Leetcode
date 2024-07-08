class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans=0;
        vector<long long> sums(nums.size(), 0);
        for (int i=0; i!=nums.size(); i++)
        {
            ans+=nums[i];
            sums[i]=ans;
        }
        int r=0;
        for (int i=nums.size()-1; i>0; i--)
        {
            if (nums[i]<sums[i-1]) return sums[i];
        }
        return -1;
    }
};