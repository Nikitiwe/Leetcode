class Solution {
public:
    bool hasValidPath(vector<vector<int>>& g) {
        if (g.size()==1&&g[0].size()==1) return 1;
        unordered_set<int> m, zero;
        int x=0, y=0;
        m.insert(300*x+y);
        char d;
        if (g[x][y]!=4)
        {
            if (g[x][y]==1) d='r';
            else if (g[x][y]==2) d='d';
            else if (g[x][y]==3) d='d';
            else if (g[x][y]==5) return 0;
            else if (g[x][y]==6) d='r';
            while (x>=0&&x<g.size()&&y>=0&&y<g[0].size())
            {
                if (d=='r')
                {
                    y++;
                    if (y==g[0].size()) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==3) d='d';
                    else if (g[x][y]==5) d='u';
                    else return 0;
                }
                else if (d=='d')
                {
                    x++;
                    if (x==g.size()) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==6) d='r';
                    else if (g[x][y]==5) d='l';
                    else return 0;
                }
                else if (d=='l')
                {
                    y--;
                    if (y==-1) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==4) d='d';
                    else if (g[x][y]==6) d='u';
                    else return 0;
                }
                else if (d=='u')
                {
                    x--;
                    if (x==-1) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==3) d='l';
                    else if (g[x][y]==4) d='r';
                    else return 0;
                }
                if (x==g.size()-1&&y==g[0].size()-1) return 1;
                m.insert(300*x+y);
            }
        }
        else
        {
            d='r';
            while (x>=0&&x<g.size()&&y>=0&&y<g[0].size())
            {
                if (d=='r')
                {
                    y++;
                    if (y==g[0].size()) break;
                    if (m.count(300*x+y)>0) break;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==3) d='d';
                    else if (g[x][y]==5) d='u';
                    else break;
                }
                else if (d=='d')
                {
                    x++;
                    if (x==g.size()) break;
                    if (m.count(300*x+y)>0) break;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==6) d='r';
                    else if (g[x][y]==5) d='l';
                    else break;
                }
                else if (d=='l')
                {
                    y--;
                    if (y==-1) break;
                    if (m.count(300*x+y)>0) break;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==4) d='d';
                    else if (g[x][y]==6) d='u';
                    else break;
                }
                else if (d=='u')
                {
                    x--;
                    if (x==-1) break;
                    if (m.count(300*x+y)>0) break;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==3) d='l';
                    else if (g[x][y]==4) d='r';
                    else break;
                }
                if (x==g.size()-1&&y==g[0].size()-1) return 1;
                m.insert(300*x+y);
            }
            m=zero;
            d='d';
            x=0; y=0;
            while (x>=0&&x<g.size()&&y>=0&&y<g[0].size())
            {
                if (d=='r')
                {
                    y++;
                    if (y==g[0].size()) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==3) d='d';
                    else if (g[x][y]==5) d='u';
                    else return 0;
                }
                else if (d=='d')
                {
                    x++;
                    if (x==g.size()) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==6) d='r';
                    else if (g[x][y]==5) d='l';
                    else return 0;
                }
                else if (d=='l')
                {
                    y--;
                    if (y==-1) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==1) ;
                    else if (g[x][y]==4) d='d';
                    else if (g[x][y]==6) d='u';
                    else return 0;
                }
                else if (d=='u')
                {
                    x--;
                    if (x==-1) return 0;
                    if (m.count(300*x+y)>0) return 0;
                    if (g[x][y]==2) ;
                    else if (g[x][y]==3) d='l';
                    else if (g[x][y]==4) d='r';
                    else return 0;
                }
                if (x==g.size()-1&&y==g[0].size()-1) return 1;
                m.insert(300*x+y);
            }
        }
        return 0;
    }
};