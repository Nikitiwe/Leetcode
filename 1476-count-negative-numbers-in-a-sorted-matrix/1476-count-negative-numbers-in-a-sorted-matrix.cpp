class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int ans=0, j=0;
        for (int i=g.size()-1; i>=0; i--)
        {
            for (j; j<g[0].size(); j++)
            {
                if (g[i][j]<0)
                {
                    ans+=g[0].size()-j;
                    break;
                }
            }
        }
        return ans;
    }
};