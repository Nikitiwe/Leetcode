class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long l=0, ans=0;
        for (long long i=0; i!=nums.size(); i++)
        {
            while (nums[i]>l+1)
            {
                ans++;
                l+=(l+1);
                if (l>=n) return ans;
            }
            l+=nums[i];
            if (l>=n) return ans;
        }
        while (l<n)
        {
            ans++;
            l+=(l+1);
        }
        return ans;
    }
};