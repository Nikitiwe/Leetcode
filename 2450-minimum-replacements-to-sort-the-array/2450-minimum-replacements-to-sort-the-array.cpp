class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int temp=nums[nums.size()-1], count;
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i]>temp)
            {
                if (nums[i]%temp==0) ans=ans+nums[i]/temp-1;
                else
                {
                    count=nums[i]/temp+1;
                    temp=nums[i]/count;
                    ans=ans+count-1;
                }
            }
            else temp=nums[i];
        }
        return ans;
    }
};