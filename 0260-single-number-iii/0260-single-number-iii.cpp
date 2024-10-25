class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]++;
            if (m[nums[i]]==2) m.erase(nums[i]);
        }
        vector<int> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans.push_back(i->first);
        }
        return ans;
    }
};