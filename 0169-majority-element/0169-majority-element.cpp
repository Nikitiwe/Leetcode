class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int ma=0, ans;
        for (int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
            if (m[nums[i]]>ma)
            {
                ma=m[nums[i]];
                ans=nums[i];
            }
        }
        return ans;
    }
};