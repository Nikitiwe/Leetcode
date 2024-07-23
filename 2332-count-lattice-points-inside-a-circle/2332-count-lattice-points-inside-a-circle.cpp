class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int xm=0, ym=0, ans=0;
        for (int i=0; i!=circles.size(); i++)
        {
            xm=max(xm, circles[i][0]+circles[i][2]);
            ym=max(ym, circles[i][1]+circles[i][2]);
            circles[i][2]*=circles[i][2];
        }
        for (int i=0; i<=xm; i++)
        {
            for (int j=0; j<=ym; j++)
            {
                for (int k=0; k!=circles.size(); k++)
                {
                    if ((circles[k][0]-i)*(circles[k][0]-i)+(circles[k][1]-j)*(circles[k][1]-j)<=circles[k][2]) {ans++; break;}
                }
            }
        }
        return ans;
    }
};