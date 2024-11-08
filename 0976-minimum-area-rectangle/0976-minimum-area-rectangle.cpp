class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        int ans=1000000007;
        for (int i=0; i!=p.size(); i++)
        {
            for (int j=i+1; j<p.size(); j++)
            {
                int tt=abs(p[i][1]-p[j][1]);
                if (p[i][0]==p[j][0]) for (int k=i+1; k<p.size(); k++)
                {
                    int t=tt*abs(p[i][0]-p[k][0]);
                    if (t>0&&t<ans) if (p[i][1]==p[k][1]) for (int a=0; a<p.size(); a++)
                    {
                        if (p[a][0]==p[k][0]&&p[a][1]==p[j][1])
                        {
                            ans=min(ans, t);
                        }
                    }
                }
            }
        }
        if (ans!=1000000007) return ans;
        else return 0;
    }
};