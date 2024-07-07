class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, temp=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==0) temp++;
            else {ans+=temp*(temp+1)/2; temp=0;}
        }
        ans+=temp*(temp+1)/2;
        return ans;
    }
};