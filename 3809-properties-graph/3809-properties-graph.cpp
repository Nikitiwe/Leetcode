class Solution {
public:
    int numberOfComponents(vector<vector<int>>& p, int k) {
        vector<vector<int>> arr(p.size(), vector<int>());
        vector<unordered_set<int>> s(p.size(), unordered_set<int>());
        for (int i=0; i<p.size(); i++)
        {
            for (int b=0; b<p[i].size(); b++) s[i].insert(p[i][b]);
            for (int j=0; j<i; j++)
            {
                int com = 0;
                for (auto a = s[j].begin(); a!=s[j].end(); a++)
                {
                    if (s[i].count(*a) > 0) com++;
                }
                if (com >= k)
                {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        int c = 0;
        int ans = 0;
        vector<int> isit(p.size(), 1);
        while (c < p.size())
        {
            ans++;
            queue<int> q;
            for (int i=0; i<p.size(); i++)
            {
                if (isit[i] == 1)
                {
                    isit[i] = 0;
                    q.push(i);
                    c++;
                    break;
                }
            }
            while (q.size() > 0)
            {
                int id = q.front();
                q.pop();
                for (int i=0; i<arr[id].size(); i++)
                {
                    if (isit[arr[id][i]] == 1)
                    {
                        isit[arr[id][i]] = 0;
                        q.push(arr[id][i]);
                        c++;
                    }
                }
            }
        }
        return ans;
    }
};