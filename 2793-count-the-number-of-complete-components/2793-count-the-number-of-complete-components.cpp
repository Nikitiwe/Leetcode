class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> arr;
        vector<int> isit(n, 1);
        int c = 0;
        while (c < n)
        {
            int id = 0;
            for (int i = 0; i<n; i++)
            {
                if (isit[i] == 1)
                {
                    id = i;
                    isit[id] = 0;
                    c++;
                    break;
                }
            }
            arr.push_back({id});
            for (int k = 0; k<arr.size(); k++)
            {
                for (int j=0; j<arr[k].size(); j++)
                {
                    for (int i=0; i!=e.size(); i++)
                    {
                        if (arr[k][j] == e[i][0] && isit[e[i][1]] == 1)
                        {
                            arr[k].push_back(e[i][1]);
                            isit[e[i][1]] = 0;
                            c++;
                        }
                        else if (arr[k][j] == e[i][1] && isit[e[i][0]] == 1)
                        {
                            arr[k].push_back(e[i][0]);
                            isit[e[i][0]] = 0;
                            c++;
                        }
                    }
                }
            }
        }
        unordered_map<int, int> m;
        for (int i=0; i!=e.size(); i++)
        {
            m[e[i][0]]++;
            m[e[i][1]]++;
        }
        int ans = 0;
        for (int k = 0; k<arr.size(); k++)
        {
            int t = arr[k].size() - 1;
            bool ise = 1;
            for (int i=0; i<arr[k].size(); i++)
            {
                if (m[arr[k][i]] != t)
                {
                    ise = 0;
                    break;
                }
            }
            if (ise == 1) ans++;
        }
        return ans;
    }
};