class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0;
        vector<int> p;
        for (int i=0; i!=points.size(); i++)
        {p.push_back(points[i][0]);}
        sort(p.begin(), p.end());
        for (int i=1; i!=p.size(); i++)
        {
            if (p[i]-p[i-1]>ans) ans=p[i]-p[i-1];
        }
        return ans;
    }
};