class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        for (int i=0; i!=points.size(); i++)
        {
            for (int j=0; j!=points.size(); j++)
            {
                if (i!=j&&points[i][0]<=points[j][0]&&points[i][1]>=points[j][1])
                {
                    bool isit=1;
                    for (int k=0; k!=points.size(); k++)
                    {
                        if (k!=i&&k!=j)
                        {
                            if (points[i][0]<=points[k][0]&&points[k][0]<=points[j][0]&&
                                points[i][1]>=points[k][1]&&points[k][1]>=points[j][1]) {isit=0; break;}
                        }
                    }
                    if (isit==1) ans++;
                }
            }
        }
        return ans;
    }
};