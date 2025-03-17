class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i<=nums.size()-k; i++)
        {
            unordered_map<int, int> t;
            for (int j=i; j<i+k; j++)
            {
                t[nums[j]]++;
            }
            for (auto it = t.begin(); it != t.end(); it++) m[it->first]++;
        }
        int ans = -1;
        //if (k == 1 || k == nums.size())
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second == 1) ans = max(ans, it->first);
        }
        return ans;
    }
};