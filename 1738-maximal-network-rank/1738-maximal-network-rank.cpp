class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        unordered_map<int, int> m;
        for (int i=0; i!=r.size(); i++)
        {
            m[r[i][0]]++;
            m[r[i][1]]++;
        }
        int ans = 0;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (i != j)
                {
                    int t = m[i] + m[j];
                    for (int a=0; a!=r.size(); a++)
                    {
                        if ((r[a][0] == i && r[a][1] == j) || (r[a][0] == j && r[a][1] == i))
                        {
                            t--;
                            break;
                        }
                    }
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};