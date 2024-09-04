class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        unordered_set<int> m;
        int ans=0, x=0, y=0, d=1, n=60001;
        for (int i=0; i!=obs.size(); i++) m.insert(n*obs[i][0]+obs[i][1]);
        for (int i=0; i!=com.size(); i++)
        {
            if (com[i]==-2) {d++; d%=4;}
            else if (com[i]==-1) {d=d+3; d%=4;}
            else if (d==0)
            {
                while (com[i]>0)
                {
                    if (m.count(n*(x+1)+y)==0)
                    {
                        x++;
                        com[i]--;
                    }
                    else break;
                }
            }
            else if (d==1)
            {
                while (com[i]>0)
                {
                    if (m.count(n*x+y+1)==0)
                    {
                        y++;
                        com[i]--;
                    }
                    else break;
                }
            }
            else if (d==2)
            {
                while (com[i]>0)
                {
                    if (m.count(n*(x-1)+y)==0)
                    {
                        x--;
                        com[i]--;
                    }
                    else break;
                }
            }
            else if (d==3)
            {
                while (com[i]>0)
                {
                    if (m.count(n*x+y-1)==0)
                    {
                        y--;
                        com[i]--;
                    }
                    else break;
                }
            }
            ans=max(ans, x*x+y*y);
        }
        return ans;
    }
};