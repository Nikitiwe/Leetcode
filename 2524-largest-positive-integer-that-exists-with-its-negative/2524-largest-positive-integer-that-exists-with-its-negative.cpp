class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> m;
        int ans=-1;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>0)
            {
                if (m.count(-nums[i])>0) ans=max(ans, nums[i]);
                m.insert(nums[i]);
            }
            else
            {
                if (m.count(-nums[i])>0) ans=max(ans, -nums[i]);
                m.insert(nums[i]);
            }
        }
        return ans;
    }
};