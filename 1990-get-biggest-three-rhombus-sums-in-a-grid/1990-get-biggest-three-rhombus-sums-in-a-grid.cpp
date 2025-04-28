class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        priority_queue<int> q;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                q.push(g[i][j]);
                for (int r=1; ; r++)
                {
                    int sum = 0;
                    if (i+r < g.size() && i-r >= 0 && j+r < g[0].size() && j-r >= 0)
                    {
                        for (int t=0; t<r; t++) sum += g[i+r-t][j+t];
                        for (int t=0; t<r; t++) sum += g[i-t][j+r-t];
                        for (int t=0; t<r; t++) sum += g[i-r+t][j-t];
                        for (int t=0; t<r; t++) sum += g[i+t][j-r+t];
                    }
                    else break;
                    q.push(sum);
                }
            }
        }
        vector<int> arr;
        while (arr.size() < 3 && q.size() > 0)
        {
            if (arr.size() == 0) arr.push_back(q.top());
            else if (arr.back() > q.top()) arr.push_back(q.top());
            q.pop();
        }
        return arr;
    }
};