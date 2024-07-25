class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int ans=0, l=0, r=0, temp=nums[0];
            while (r<nums.size())
            {
                if (temp<k)
                {
                    ans+=r-l+1;
                    if (r<nums.size()-1) r++;
                    else break;
                    temp*=nums[r];
                }
                else
                {
                    if (l<nums.size()-1)
                    {
                        temp/=nums[l];
                        l++;
                    }
                    else break;
                    if (l>r)
                    {
                        r++;
                        temp=nums[r];
                       // if (temp<k) ans++;
                    }
                }
            }
            return ans;
    }
};