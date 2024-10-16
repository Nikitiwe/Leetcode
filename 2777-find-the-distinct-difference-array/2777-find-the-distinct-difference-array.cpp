class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> l, r;
        int a=0, b=0;
        vector<int> ans(nums.size(), 0);
        for (int i=0; i!=nums.size(); i++)
        {
            r[nums[i]]++;
        }
        b=r.size();
        for (int i=0; i!=nums.size(); i++)
        {
            l[nums[i]]++;
            if (l[nums[i]]==1) a++;
            r[nums[i]]--;
            if (r[nums[i]]==0) b--;
            ans[i]=a-b;
        }
        return ans;
    }
};