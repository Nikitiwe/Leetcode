bool sort1(vector<int> v1, vector<int> v2)
{
    if (v1[0] == v2[0]) return v1[1] > v2[1];
    else return v1[0] < v2[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(), points.end(), sort1);
        for (int i=0; i!=points.size(); i++)
        {
            for (int j=i+1; j<points.size(); j++)
            {
                if (points[i][1]>=points[j][1])
                {
                    bool isit=1;
                    for (int k=i+1; k<j; k++)
                    {
                        if (points[i][1]>=points[k][1]&&points[k][1]>=points[j][1]) {isit=0; break;}
                    }
                    if (isit==1) ans++;
                }
            }
        }
        return ans;
    }
};