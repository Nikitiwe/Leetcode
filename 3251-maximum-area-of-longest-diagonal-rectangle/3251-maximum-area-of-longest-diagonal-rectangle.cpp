class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int d2=0, s=0;
        for (int i=0; i!=d.size(); i++)
        {
            int t=d[i][0]*d[i][0]+d[i][1]*d[i][1];
            if (t>d2)
            {
                d2=t;
                s=d[i][0]*d[i][1];
            }
            else if (t==d2)
            {
                s=max(s, d[i][0]*d[i][1]);
            }
        }
        return s;
    }
};