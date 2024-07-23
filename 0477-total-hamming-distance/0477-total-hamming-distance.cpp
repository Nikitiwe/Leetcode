class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> zero(31, nums.size()), one(31, 0);
        int ans=0, temp;
        for (int i=0; i!=nums.size(); i++)
        {
            temp=0;
            while(nums[i]>0)
            {
                if (nums[i]%2==1)
                {
                    zero[temp]--;
                    one[temp]++;
                }
                nums[i]/=2;
                temp++;
            }
        }
        for (int i=0; i!=31; i++)
        {
            ans+=zero[i]*one[i];
        }
        return ans;
    }
};