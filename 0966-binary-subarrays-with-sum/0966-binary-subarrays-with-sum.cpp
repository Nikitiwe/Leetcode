class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> sums(nums.size()+1, 0);
        int s=0, r=0, f, ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            s+=nums[i];
            sums[i+1]=s;
        }
        s=0;
        for (int i=0; i!=sums.size(); i++)
        {
            f=1;
            r=max(s, i+1);
            while (r<sums.size())
            {
                if (sums[r]-sums[i]==goal)
                {
                    if (f==1) {f=0; s=r;}
                    ans++;
                }
                else if (sums[r]-sums[i]>goal) break;
                r++;
            }
        }
        return ans;
    }
};