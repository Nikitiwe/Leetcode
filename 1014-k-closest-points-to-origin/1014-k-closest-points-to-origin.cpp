bool comp(vector<int> a, vector<int> b) 
{ 
    return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]; 
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort (points.begin(), points.end(), comp);
        vector<vector<int>> ans(points.begin(), points.begin()+k);
        return ans;
    }
};