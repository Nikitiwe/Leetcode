class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int ans=0;
        vector<vector<int>> next=m;
        for (int i=0; i!=m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                ans+=m[i][j];
            }
        }
        for (int k=2; k<max(m.size(), m[0].size()); k++)
        {
            for (int i=k-1; i<m.size(); i++)
            {
                for (int j=k-1; j<m[0].size(); j++)
                {
                    if (m[i][j]>0&&m[i-1][j-1]==k-1&&m[i][j-1]==k-1&&m[i-1][j]==k-1)
                    {
                        ans++;
                        next[i][j]=k;
                    }
                }
            }
            m=next;
        }
        return ans;
    }
};