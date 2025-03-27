class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ansr(n, 999), ansb = ansr;
        ansr[0] = 0;
        ansb[0] = 0;
        queue<pair<int, char>> q;
        q.push({0, 'r'});
        q.push({0, 'b'});
        while (q.size() > 0)
        {
            int x = q.front().first;
            char c = q.front().second;
            q.pop();
            if (c == 'r')
            {
                for (int i=0; i!=blueEdges.size(); i++)
                {
                    if (blueEdges[i][0] == x && ansb[blueEdges[i][1]] > ansr[x] + 1)
                    {
                        ansb[blueEdges[i][1]] = ansr[x] + 1;
                        q.push({blueEdges[i][1], 'b'});
                    }
                }
            }
            else
            {
                for (int i=0; i!=redEdges.size(); i++)
                {
                    if (redEdges[i][0] == x && ansr[redEdges[i][1]] > ansb[x] + 1)
                    {
                        ansr[redEdges[i][1]] = ansb[x] + 1;
                        q.push({redEdges[i][1], 'r'});
                    }
                }
            }
        }
        for (int i=0; i!=n; i++)
        {
            ansr[i] = min(ansr[i], ansb[i]);
            if (ansr[i] == 999) ansr[i] = -1;
        }
        return ansr;
    }
};