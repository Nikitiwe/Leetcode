class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mm) {
        vector<vector<int>> m (mm.size(), vector<int> (mm[0].size(), 0));
        for (int i=0; i<m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                if (mm[i][j]=='1') m[i][j]=1;
                else m[i][j]=0;
            }
        }
        for (int i=1; i<m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                if (m[i][j]!=0) m[i][j]+=m[i-1][j];
            }
        }
        int ans=0;
        for (int i=0; i<m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                int mi=m[i][j];
                for (int k=j; k<m[0].size(); k++)
                {
                    if (m[i][k]==0) break;
                    mi=min(mi, m[i][k]);
                    ans=max(ans, mi*(k-j+1));
                }
            }
        }
        return ans;
    }
};