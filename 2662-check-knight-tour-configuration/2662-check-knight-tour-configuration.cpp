class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& g) {
        if (g[0][0]!=0) return 0;
        int x=0, y=0, n=g.size(), nn=n*n;
        for (int i=1; i<nn; i++)
        {
            if (x-2>=0&&y-1>=0&&g[x-2][y-1]==i) {x-=2; y-=1;}
            else if (x-1>=0&&y-2>=0&&g[x-1][y-2]==i) {x-=1; y-=2;}
            else if (x-1>=0&&y+2<n&&g[x-1][y+2]==i) {x-=1; y+=2;}
            else if (x-2>=0&&y+1<n&&g[x-2][y+1]==i) {x-=2; y+=1;}
            else if (x+2<n&&y+1<n&&g[x+2][y+1]==i) {x+=2; y+=1;}
            else if (x+2<n&&y-1>=0&&g[x+2][y-1]==i) {x+=2; y-=1;}
            else if (x+1<n&&y+2<n&&g[x+1][y+2]==i) {x+=1; y+=2;}
            else if (x+1<n&&y-2>=0&&g[x+1][y-2]==i) {x+=1; y-=2;}
            else return 0;
        }
        return 1;
    }
};