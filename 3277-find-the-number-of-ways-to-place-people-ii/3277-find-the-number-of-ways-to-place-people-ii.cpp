bool ssort (vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0]) return a[1] > b[1];
    else return a[0] < b[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(), points.end(), ssort);
        for (int i=0; i!=points.size(); i++)
        {
            for (int j=i+1; j<points.size(); j++)
            {
                if (points[i][0]<=points[j][0]&&points[i][1]>=points[j][1])
                {
                    bool isit=1;
                    for (int k=i+1; k<j; k++)
                    {
                        if (points[i][0]<=points[k][0]&&points[k][0]<=points[j][0]&&
                            points[i][1]>=points[k][1]&&points[k][1]>=points[j][1]) {isit=0; break;}
                    }
                    if (isit==1) ans++;
                }
            }
        }
        return ans;
    }
};