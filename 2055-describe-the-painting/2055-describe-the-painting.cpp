class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {
        int ma = 0;
        for (int i=0; i!=s.size(); i++) ma = max(ma, s[i][1]);
        vector<long long> arr(ma + 2, 0);
        unordered_set<int> m;
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i][0]] += s[i][2];
            arr[s[i][1]] -= s[i][2];
            m.insert(s[i][1]);
        }
        vector<vector<long long>> ans;
        for (int i=0; i+1<arr.size(); i++)
        {
            arr[i+1] += arr[i];
            if (arr[i] > 0)
            {
                if (ans.size() > 0)
                {
                    if (ans[ans.size()-1][1] == i && ans[ans.size()-1][2] == arr[i] && m.count(i) == 0)
                    {
                        ans[ans.size()-1][1] = i+1;
                    }
                    else
                    {
                        ans.push_back({i, i+1, arr[i]});
                    }
                }
                else ans.push_back({i, i+1, arr[i]});
            }
        }
        return ans;
    }
};