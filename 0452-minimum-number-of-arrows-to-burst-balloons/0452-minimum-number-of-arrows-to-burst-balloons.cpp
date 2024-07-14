bool sortt(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sortt);
        vector<int> isit(points.size(), 0);
        int ans=1, i=0, temp=points[0][1];
        while (isit[points.size()-1]==0)
        {
            while (points[i][0]<=temp&&temp<=points[i][1]&&isit[i]==0)
            {
                isit[i]=1;
                if (i==points.size()-1) return ans;
                i++;
            }
            ans++;
            temp=points[i][1];
        }
        return ans;
    }
};