class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        int ans=-1, t=20000;
        for (int i=0; i!=p.size(); i++)
        {
            if (p[i][0]==x)
            {
                if (abs(y-p[i][1])<t)
                {
                    t=abs(y-p[i][1]);
                    ans=i;
                }
            }
            else if (p[i][1]==y)
            {
                if (abs(x-p[i][0])<t)
                {
                    t=abs(x-p[i][0]);
                    ans=i;
                }
            }
        }
        return ans;
    }
};