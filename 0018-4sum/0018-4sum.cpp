class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& numss, int k) {
        unordered_map<int, int> q;
        for (int i=0; i!=numss.size(); i++)
        {
            q[numss[i]]++;
            if (q[numss[i]] == 5) q[numss[i]]--;
        }
        vector<long> nums;
        for (auto i = q.begin(); i!=q.end(); i++)
        {
            while (i->second > 0)
            {
                nums.push_back(i->first);
                i->second--;
            }
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<tuple<int, int, int, int>> s;
        unordered_map<long, vector<pair<int, int>>> m;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                m[nums[i] + nums[j]].push_back({i, j});
            }
        }
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                long t = k - nums[i] - nums[j];
                if (m.count(t) != 0)
                {
                    for (int a = 0; a<m[t].size(); a++)
                    {
                        if (m[t][a].second < i) s.insert({nums[m[t][a].first], nums[m[t][a].second], nums[i], nums[j]});
                    }
                }
            }
        }
        for (auto i = s.begin(); i!=s.end(); i++)
        {
            auto [a, b, c, d] = *i;
            ans.push_back({a, b, c, d});
        }
        return ans;
    }
};