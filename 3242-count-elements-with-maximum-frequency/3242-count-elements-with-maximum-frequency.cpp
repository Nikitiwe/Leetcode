class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int t=0, ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]++;
            t=max(t, m[nums[i]]);
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==t) ans+=t;
        }
        return ans;
    }
};