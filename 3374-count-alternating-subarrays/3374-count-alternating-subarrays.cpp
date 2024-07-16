class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
            long long ans=1, temp=1;
            for (int i=1; i!=nums.size(); i++)
            {
                if (nums[i]!=nums[i-1]) {temp++; ans+=temp;}
                else {temp=1; ans+=temp;}
            }
            return ans;
    }
};