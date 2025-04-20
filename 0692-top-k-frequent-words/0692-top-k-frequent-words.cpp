class Solution {
public:
    vector<string> topKFrequent(vector<string>& s, int k) {
        unordered_map<string, int> m;
        for (int i=0; i!=s.size(); i++) m[s[i]]++;
        vector<pair<int, string>> arr;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            arr.push_back({i->second, i->first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<string> ans;
        vector<vector<string>> v(1, vector<string>());
        int c = arr[0].first;
        int id = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i].first == c) v[id].push_back(arr[i].second);
            else
            {
                id++;
                v.push_back(vector<string>());
                c = arr[i].first;
                v[id].push_back(arr[i].second);
            }
        }
        for (int i=0; i!=v.size(); i++)
        {
            sort(v[i].begin(), v[i].end());
            for (int j=0; j!=v[i].size(); j++)
            {
                ans.push_back(v[i][j]);
                if (ans.size() == k) break;
            }
            if (ans.size() == k) break;
        }
        return ans;
    }
};