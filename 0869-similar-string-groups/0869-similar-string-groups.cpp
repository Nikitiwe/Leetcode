class Solution {
public:
    int f(vector<string>& s, int a, int b)
    {
        vector<int> arr;
        for (int i=0; i!=s[0].size(); i++)
        {
            if (s[a][i] != s[b][i]) arr.push_back(i);
            if (arr.size() > 2) return -1;
        }
        if (arr.size() == 1) return -1;
        if (arr.size() == 0) return 1;
        if (s[a][arr[0]] == s[b][arr[1]] && s[a][arr[1]] == s[b][arr[0]]) return 1;
        return -1;
    }

    int numSimilarGroups(vector<string>& s) {
        vector<vector<int>> arr;
        arr.push_back({0});
        vector<vector<int>> ise(s.size(), vector<int>(s.size(), 0));
        vector<bool> h(s.size(), 0);
        h[0] = 1;
        int c = 1;
        vector<int> q;
        while (c < s.size())
        {
            int t = arr[arr.size()-1].back();
            for (int i=0; i!=s.size(); i++)
            {
                if (h[i] == 0)
                {
                    if (ise[i][t] == 0)
                    {
                        ise[i][t] = f(s, i, t);
                        ise[t][i] = f(s, i, t);
                    }
                    if (ise[i][t] == 1)
                    {
                        h[i] = 1;
                        q.push_back(i);
                        c++;
                    }
                }
            }
            if (q.size() > 0)
            {
                arr[arr.size()-1].push_back(q.back());
                q.pop_back();
            }
            else
            {
                for (int i=0; i!=s.size(); i++)
                {
                    if (h[i] == 0)
                    {
                        h[i] = 1;
                        arr.push_back({i});
                        c++;
                        break;
                    }
                }
            }
        }
        return arr.size();
    }
};