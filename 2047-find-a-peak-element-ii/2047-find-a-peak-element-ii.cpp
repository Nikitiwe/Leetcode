class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat[0][0], x=0, y=0, xm=0, ym=0;
        while (1)
        {
            if (x>0) if (mat[x-1][y]>m) {xm=x-1; m=mat[x-1][y];}
            if (x<mat.size()-1) if (mat[x+1][y]>m) {xm=x+1; m=mat[x+1][y];}
            if (y>0) if (mat[x][y-1]>m) {ym=y-1; xm=x; m=mat[x][y-1];}
            if (y<mat[0].size()-1) if (mat[x][y+1]>m) {ym=y+1; xm=x; m=mat[x][y+1];}
            if (mat[x][y]==m) return {x, y};
            else {x=xm; y=ym;}
        }
        return {x, y};
    }
};