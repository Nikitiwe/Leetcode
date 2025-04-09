class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        queue<vector<int>> p;
        p.push({0});
        while (p.size() > 0)
        {
            vector<int> path = p.front();
            int end = path.back();
            p.pop();
            if (end == g.size() - 1) ans.push_back(path);
            for (int i=0; i!=g[end].size(); i++)
            {
                vector<int> t = path;
                t.push_back(g[end][i]);
                p.push(t);
            }
        }
        return ans;
    }
};