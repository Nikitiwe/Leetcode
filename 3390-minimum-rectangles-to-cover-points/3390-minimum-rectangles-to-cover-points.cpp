class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> x(points.size(), 0);
        for (int i=0; i!=points.size(); i++)
        { x[i]=points[i][0]; }
        sort(x.begin(), x.end());
        int ans=1, temp=x[0], i=0;
        while (i<=points.size()-1)
        {
            if (x[i]-temp<=w) { i++; }
            else { ans++; temp=x[i]; i++;}
        }
        return ans;
    }
};