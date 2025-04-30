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
        unordered_map<string, int> id;
        int a = 0;
        vector<priority_queue<int>> arr;
        vector<bool> isit;
        for (int i=0; i!=n.size(); i++)
        {
            if (id.count(n[i]) == 0)
            {
                id[n[i]] = a;
                arr.push_back(priority_queue<int>());
                isit.push_back(0);
                a++;
            }
            if (isit[id[n[i]]] == 0)
            {
                if (arr[id[n[i]]].size() < 2) arr[id[n[i]]].push(f(t[i]));
                else
                {
                    if (arr[id[n[i]]].size() == 2)
                    {
                        if (arr[id[n[i]]].top() - 60 <= f(t[i]) ) isit[id[n[i]]] = 1;
                        arr[id[n[i]]].pop();
                        arr[id[n[i]]].push(f(t[i]));
                    }
                }
            }
        }
        vector<string> res;
        for (int i=0; i!=n.size(); i++)
        {
            if (isit[id[n[i]]] == 1)
            {
                res.push_back(n[i]);
                isit[id[n[i]]] = 0;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};