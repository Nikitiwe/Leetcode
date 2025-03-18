class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        vector<vector<int>> d = g;
        for (int i=0; i!=g.size(); i++)
        {
            priority_queue<int> q;
            for (int j=0; i+j<g.size(); j++)
            {
                q.push(g[i+j][j]);
            }
            for (int j=0; i+j<g.size(); j++)
            {
                d[i+j][j] = q.top();
                q.pop();
            }
        }
        for (int i=1; i<g.size(); i++)
        {
            priority_queue<int> q;
            for (int j=0; i+j<g.size(); j++)
            {
                q.push(- g[j][i+j]);
            }
            for (int j=0; i+j<g.size(); j++)
            {
                d[j][i+j] =  - q.top();
                q.pop();
            }
        }
        return d;
    }
};