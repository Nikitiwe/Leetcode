class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> m(nums.begin(), nums.end());
        int s=m.size(), ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            unordered_set<int> n;
            for (int j=i; j<nums.size(); j++)
            {
                n.insert(nums[j]);
                if (n.size()==s)
                {
                    ans+=(nums.size()-j);
                    break;
                }
            }
        }
        return ans;
    }
};