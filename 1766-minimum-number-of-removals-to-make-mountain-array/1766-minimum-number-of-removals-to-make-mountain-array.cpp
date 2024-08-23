class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int ans=1001, n=nums.size();
        vector<int> l(n, 1), r(n, 1);
        /*vector<bool> isl(n, 1), isr(n, 1);
        for (int i=1; i<n-1; i++)
        {
            if (nums[i]<=nums[i-1]) isl[i]=0;
            else break;
        }
        for (int i=n-2; i>1; i--)
        {
            if (nums[i]<=nums[i+1]) isr[i]=0;
            else break;
        }*/
        for (int i=1; i<n-1; i++)
        {
            for (int j=i-1; j>=0; j--) if (nums[j]<nums[i]) l[i]=max(l[j]+1, l[i]);
        }
        for (int i=n-2; i>0; i--)
        {
            for (int j=i+1; j<n; j++) if (nums[j]<nums[i]) r[i]=max(r[j]+1, r[i]);
        }
        for (int i=1; i<n-1; i++)
        {
            if (l[i]>1&&r[i]>1) ans=min(ans, n-l[i]-r[i]+1);
        }
        return ans;
    }
};