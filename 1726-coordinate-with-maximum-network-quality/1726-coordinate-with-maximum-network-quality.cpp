class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& tow, int r) {
        int m=0, n=0;
        for (int i=0; i!=tow.size(); i++)
        {
            m=max(m, tow[i][0]);
            n=max(n, tow[i][1]);
        }
        vector<vector<int>> arr(m+1, vector<int> (n+1, 0));
        int rr=r*r;
        float d;
        for (int i=0; i!=tow.size(); i++)
        {
            for (int a=max(tow[i][0]-r, 0); a<=min(tow[i][0]+r, m); a++)
            {
                for (int b=max(tow[i][1]-r, 0); b<=min(tow[i][1]+r, n); b++)
                {
                    {
                        d=(tow[i][0]-a)*(tow[i][0]-a)+(tow[i][1]-b)*(tow[i][1]-b);
                        if (d<=rr) arr[a][b]+=tow[i][2]/(1+sqrt(d));
                    }
                }
            }
        }
        int x=0, y=0;
        m=arr[0][0];
        for (int i=0; i<arr.size(); i++)
        {
            for (int j=0; j<arr[0].size(); j++)
            {
                if (arr[i][j]>m)
                {
                    m=arr[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        return {x, y};
    }
};