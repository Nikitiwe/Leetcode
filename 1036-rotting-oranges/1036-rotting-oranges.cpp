class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        vector<vector<int>> prev=g, next=g;
        int c=0;
        for (int i=0; i!=g.size(); i++)
        {
            for (int j=0; j!=g[0].size(); j++)
            {
                if (g[i][j]==1) c++;
            }
        }
        if (c==0) return 0;
        int i=0;
        while (1)
        {
            i++;
            int s=c;

            for (int i=0; i!=g.size(); i++)
            {
                for (int j=0; j!=g[0].size(); j++)
                {
                    if (prev[i][j]==2)
                    {
                        if (i>0&&next[i-1][j]==1)
                        {
                            next[i-1][j]=2;
                            c--;
                        }
                        if (j>0&&next[i][j-1]==1)
                        {
                            next[i][j-1]=2;
                            c--;
                        }
                        if (i<g.size()-1&&next[i+1][j]==1)
                        {
                            next[i+1][j]=2;
                            c--;
                        }
                        if (j<g[0].size()-1&&next[i][j+1]==1)
                        {
                            next[i][j+1]=2;
                            c--;
                        }
                    }
                }
            }
            if (c==0) return i;
            if (c==s) return -1;
            prev=next;
        }
        return -1;
        
    }
};