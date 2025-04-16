class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for (int i=0; i<nums.size()-k+1; i++)
        {
            unordered_map<int, int> m;
            for (int j=i; j<i+k; j++) m[nums[j]]++;
            vector<pair<int, int>> t;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                t.push_back({it->second, it->first});
            }
            sort(t.rbegin(), t.rend());
            int sum = 0, c = 1;
            for (int j=0; j!=t.size(); j++)
            {
                if (j>0 && t[j].second != t[j-1].second) c++;
                if (c > x) break;
                sum += t[j].first * t[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};