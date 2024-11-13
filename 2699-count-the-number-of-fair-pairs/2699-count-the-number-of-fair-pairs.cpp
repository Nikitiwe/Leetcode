class Solution {
public:
    long long countFairPairs(vector<int>& nums, int a, int b) {
        sort(nums.begin(), nums.end());
        long long ans=0;
        int l=nums.size()-1, r=nums.size()-1;
        for (int i=0; i!=nums.size(); i++)
        {
            while (l>=0&&nums[i]+nums[l]>=a) l--;
            while (r>=0&&nums[i]+nums[r]>b) r--;
            if (r>=0&&l>=0) ans+=r-l;
            else if (r>=0) ans+=r+1;

            if (i>l&&i<=r) ans--;
        }
        return ans/2;
    }
};