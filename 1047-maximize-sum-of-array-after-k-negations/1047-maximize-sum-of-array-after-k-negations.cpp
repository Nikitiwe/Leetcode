class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]<0)
            {
                nums[i]*=-1;
                k--;
            }
            else break;
            if (k==0) break;
        }
        sort(nums.begin(), nums.end());
        if (k%2==1) nums[0]*=-1;
        int ans=0;
        for (int i=0; i!=nums.size(); i++) ans+=nums[i];
        return ans;
    }
};