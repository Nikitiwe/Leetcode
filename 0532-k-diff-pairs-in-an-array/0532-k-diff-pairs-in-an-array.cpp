class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[nums[i]]++;
        int ans=0;
        if (k>0) for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (m.count(i->first+k)>0) ans++;
        }
        else for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second>1) ans++;
        }
        return ans;
    }
};