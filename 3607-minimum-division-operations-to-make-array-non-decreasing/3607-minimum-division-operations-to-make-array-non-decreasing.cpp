class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for (int i=nums.size()-2; i>=0; i--)
        {
            while (nums[i]>nums[i+1])
            {
                int t=nums[i];
                ans++;
                for (int j=2; j*j<=nums[i]; j++)
                {
                    if (nums[i]%j==0)
                    {
                        nums[i]=j;
                        break;
                    }
                }
                if (t==nums[i]) return -1;
            }
        }
        return ans;
    }
};