class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans(nums.size(), 0);
        unordered_map<int, int> add, prev, zero;
        unordered_map<int, long long> m, mzero;
        for (int i=0; i!=nums.size(); i++)
        {
            if (prev.count(nums[i])>0)
            {
                m[nums[i]]+=(long long)add[nums[i]]*(i-prev[nums[i]]);
                ans[i]+=m[nums[i]];
                add[nums[i]]++;
                prev[nums[i]]=i;
            }
            else
            {
                add[nums[i]]++;
                prev[nums[i]]=i;
            }
        }
        m=mzero; add=zero; prev=zero;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (prev.count(nums[i])>0)
            {
                m[nums[i]]+=(long long)add[nums[i]]*(prev[nums[i]]-i);
                ans[i]+=m[nums[i]];
                add[nums[i]]++;
                prev[nums[i]]=i;
            }
            else
            {
                add[nums[i]]++;
                prev[nums[i]]=i;
            }
        }
        return ans;
    }
};