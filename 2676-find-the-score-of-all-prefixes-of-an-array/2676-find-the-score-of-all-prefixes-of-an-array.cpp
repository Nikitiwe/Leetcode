class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long sum=0;
        int m=0;
        for (int i=0; i!=nums.size(); i++)
        {
            m=max(nums[i], m);
            sum=sum+nums[i]+m;
            ans.push_back(sum);
        }
        return ans;
    }
};