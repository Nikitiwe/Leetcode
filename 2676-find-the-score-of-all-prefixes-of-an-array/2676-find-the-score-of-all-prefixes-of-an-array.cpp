class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long sum=0;
        int max=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>max) max=nums[i];
            sum=sum+nums[i]+max;
            ans.push_back(sum);
        }
        return ans;
    }
};