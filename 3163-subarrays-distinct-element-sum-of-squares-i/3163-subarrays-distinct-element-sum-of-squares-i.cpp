class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++)
            {
                unordered_set<int> m;
                for (int a=i; a<=j; a++)
                {
                    m.insert(nums[a]);
                }
                ans+=m.size()*m.size();
            }
        }
        return ans;
    }
};