class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans=0, temp, t;
        for (int i=0; i!=nums.size(); i++)
        {
            temp=nums[i];
            if (temp==k) ans++;
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[j]%temp==0||temp%nums[j]==0) temp=max(nums[j], temp);
                else
                {
                    t=gcd(temp, nums[j]);
                    temp*=nums[j];
                    temp/=t;
                }
                if (temp==k) ans++;
                else if (temp>k) break;
            }
        }
        return ans;
    }
};