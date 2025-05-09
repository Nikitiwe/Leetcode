class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& e) {
        vector<vector<int>> arr(n, vector<int>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(e[i][1]);
            arr[e[i][1]].push_back(e[i][0]);
        }
        int ans = 100000;
        for (int k = 0; k!=n; k++)
        {
            vector<int> c(n, -1);
            c[k] = 0;
            queue<int> q; // индекс куда
            queue<int> f; // индекс откуда
            q.push(k);
            f.push(k);
            while (q.size() > 0)
            {
                int id = q.front();
                int from = f.front();
                q.pop();
                f.pop();
                bool isend = 0;
                for (int j=0; j<arr[id].size(); j++) if (arr[id][j] != from)
                {
                    if (c[arr[id][j]] == -1)
                    {
                        c[arr[id][j]] = c[id] + 1;
                        q.push(arr[id][j]);
                        f.push(id);
                    }
                    else
                    {
                        ans = min(ans, c[arr[id][j]] + c[id] + 1);
                        /*isend = 1;
                        break;*/
                    }
                }
                //if (isend == 1) break;
            }
        }
        
        if (ans == 100000) return -1;
        else return ans;
    }
};