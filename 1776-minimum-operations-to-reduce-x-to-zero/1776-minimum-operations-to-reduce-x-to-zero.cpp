class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(), sum=0, l=0, r=n, ans=n+1;
        while (l<r&&sum<x)
        {
            sum+=nums[l];
            l++;
        }
        l--;
        if (sum<x) return -1;
        if (sum==x) ans=min(ans, l+1);
        while (1)
        {
            if (sum>=x&&l>=0)
            {
                sum-=nums[l];
                l--;
                if (sum==x) ans=min(ans, l+1+n-r);
            }
            else if (sum<x&&r>=0)
            {
                r--;
                sum+=nums[r];
                if (sum==x) ans=min(ans, l+1+n-r);
            }
            else break;
        }
        if (ans==n+1) return -1;
        return ans;
    }
};