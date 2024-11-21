class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> t=nums;
        sort(t.rbegin(), t.rend());
        unordered_map<int, int> m;
        for (int i=0; i!=k; i++) m[t[i]]++;
        vector<int> ans(k, 0);
        int j=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i])>0)
            {
                ans[j]=nums[i];
                m[nums[i]]--;
                if (m[nums[i]]==0) m.erase(nums[i]);
                j++;
            }
        }
        return ans;
    }
};