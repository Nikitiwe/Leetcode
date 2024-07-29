class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%k==0) nums[i]/=k;
            else nums[i]=0;
        }
        int temp, ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            temp=nums[i];
            for (int j=i; j!=nums.size(); j++)
            {
                if (nums[j]==0) break;
                temp=gcd(temp, nums[j]);
                if (temp==1) ans++;
            }
        }
        return ans;
    }
};