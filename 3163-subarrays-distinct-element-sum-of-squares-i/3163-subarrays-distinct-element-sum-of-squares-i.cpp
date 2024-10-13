class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            unordered_set<int> m;
            for (int j=i; j<nums.size(); j++)
            {
                m.insert(nums[j]);
                ans+=m.size()*m.size();
            }
        }
        return ans;
    }
};