class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, l=0, r=0, temp=1-nums[0], sum=nums[0];
        if (temp<=k) ans=max(ans, sum+temp);
        while (r!=nums.size()-1)
        {
            if (temp<k&&r<nums.size()-1)
            {
                r++;
                if (nums[r]==0) {temp++; ans=max(ans, sum+temp);}
                else
                {
                    sum++;
                    ans=max(ans, sum+temp);
                }
            }
            else if (temp==k&&r<nums.size()-1)
            {
                if (nums[r+1]==1)
                {
                    r++;
                    sum++;
                    ans=max(ans, sum+temp);
                }
                else
                {
                    if (nums[l]==1) sum--;
                    else temp--;
                    l++;
                    if (r<l) {r++; temp=1-nums[l]; sum=nums[l];}
                }
            }
            else
            {
                r++;
                l++;
                temp=1-nums[l];
                sum=nums[l];
            }
        }
        return ans;
    }
};