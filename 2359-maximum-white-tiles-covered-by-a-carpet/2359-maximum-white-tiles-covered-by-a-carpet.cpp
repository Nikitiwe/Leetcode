class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& nums, int n) {
        sort(nums.begin(), nums.end());
        int l=0, s=min(nums[l][0]+n-1, nums[l][1])-nums[l][0]+1, ans=s;
        vector<int> rem(nums.size(), 0);
        if (ans==n) return ans;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i>0) s-=(nums[i-1][1]-nums[i-1][0]+1);
            if (rem[l]>0)
            {
                s-=rem[l];
                rem[l]=0;
                int t=(min(nums[i][0]+n-1, nums[l][1])-nums[l][0]+1);
                if (t<nums[l][1]-nums[l][0]+1)
                {
                    s+=t;
                    rem[l]=t;
                }
                else s+=t;
            }
            while (l+1<nums.size()&&nums[l+1][0]<=nums[i][0]+n-1)
            {
                l++;
                int t=(min(nums[i][0]+n-1, nums[l][1])-nums[l][0]+1);
                if (t<nums[l][1]-nums[l][0]+1)
                {
                    s+=t;
                    rem[l]=t;
                }
                else s+=t;
            }
            ans=max(ans, s);
            if (ans==n) return ans;
        }
        return ans;
    }
};