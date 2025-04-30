class Solution {
public:
    int f(string &s)
    {
        return - ((s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0'));
    }
    vector<string> alertNames(vector<string>& n, vector<string>& t) {
        vector<pair<string, string>> v;
        for (int i=0; i!=n.size(); i++)
        {
            v.push_back({t[i], n[i]});
        }
        sort(v.begin(), v.end());
        for (int i=0; i!=n.size(); i++)
        {
            n[i] = v[i].second;
            t[i] = v[i].first;
        }
        unordered_set<string> ans;
        unordered_map<string, int> id;
        int a = 0;
        vector<priority_queue<int>> arr;
        for (int i=0; i!=n.size(); i++)
        {
            if (id.count(n[i]) == 0)
            {
                id[n[i]] = a;
                arr.push_back(priority_queue<int>());
                a++;
            }
            if (arr[id[n[i]]].size() < 2) arr[id[n[i]]].push(f(t[i]));
            else
            {
                if (arr[id[n[i]]].size() == 2)
                {
                    if (arr[id[n[i]]].top() - 60 <= f(t[i]) ) ans.insert(n[i]);
                    arr[id[n[i]]].pop();
                    arr[id[n[i]]].push(f(t[i]));
                }
            }
        }
        vector<string> res;
        for (auto i = ans.begin(); i!= ans.end(); i++) res.push_back(*i);
        sort(res.begin(), res.end());
        return res;
    }
};