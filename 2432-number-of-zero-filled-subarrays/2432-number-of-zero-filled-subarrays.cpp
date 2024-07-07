class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int temp=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==0) {temp++; ans+=temp;}
            else temp=0;
        }
        return ans;
    }
};