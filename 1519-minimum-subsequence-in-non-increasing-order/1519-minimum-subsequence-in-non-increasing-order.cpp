class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum=0, s=0;
        for (int i=0; i!=nums.size(); i++) sum+=nums[i];
        sort(nums.rbegin(), nums.rend());
        sum/=2;
        vector<int> ans;
        for (int i=0; i!=nums.size(); i++)
        {
            s+=nums[i];
            ans.push_back(nums[i]);
            if (s>sum) break;
        }
        return ans;        
    }
};