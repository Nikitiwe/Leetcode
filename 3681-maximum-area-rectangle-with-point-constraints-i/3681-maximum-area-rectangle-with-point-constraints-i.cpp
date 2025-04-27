class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& p) {
        int ans = -1;
        for (int i=0; i!=p.size(); i++)
        {
            for (int j=0; j!=p.size(); j++)
            {
                if (j != i && p[i][0] == p[j][0] && p[i][1] < p[j][1]) for (int a=0; a!=p.size(); a++)
                {
                    if (a!=i && a!=j && p[i][1] == p[a][1] && p[i][0] < p[a][0]) for (int b=0; b!=p.size(); b++)
                    {
                        if (b!=i && b!=j && b!=a && p[j][1] == p[b][1] && p[a][0] == p[b][0])
                        {
                            bool isit = 1;
                            if (p.size() == 4) ans = max(ans, (p[i][1] - p[j][1])*(p[i][0] - p[a][0]));
                            else for (int x=0; x!=p.size(); x++)
                            {
                                if (x!=i && x!=j && x!=a && x!=b)
                                {
                                    if ( (p[x][0] < p[i][0]) || (p[a][0] < p[x][0]) ||
                                        (p[x][1] < p[i][1]) || (p[j][1] < p[x][1]) ) continue;
                                    else
                                    {
                                        isit = 0;
                                        break;
                                    }
                                }
                            }
                            if (isit == 1) ans = max(ans, (p[i][1] - p[j][1])*(p[i][0] - p[a][0]));
                        }
                    }
                }
            }
        }
        return ans;
    }
};