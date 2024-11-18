class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), 0);
        int a=0;
        for (int i=0; i!=nums.size(); i++)
        {
            a*=2;
            a+=nums[i];
            a%=5;
            if (a==0) ans[i]=1;
        }
        return ans;
    }
};