class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int source, int destination) {
        if (source == destination) return 1;
        vector<vector<int>> arr(n, vector<int>());
        for (int i=0; i!=e.size(); i++)
        {
            arr[e[i][0]].push_back(e[i][1]);
            arr[e[i][1]].push_back(e[i][0]);
        }
        int t = source;
        queue<int> id;
        id.push(source);
        vector<bool> isit(n, 1);
        isit[source] = 0;
        while (id.size() > 0)
        {
            t = id.front();
            id.pop();
            for (int i=0; i<arr[t].size(); i++)
            {
                if (isit[arr[t][i]] == 1)
                {
                    if (arr[t][i] == destination) return 1;
                    id.push(arr[t][i]);
                    isit[arr[t][i]] = 0;
                }
            }
        }
        return 0;
    }
};