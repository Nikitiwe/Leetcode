bool ssort (vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int ans = a.size();
        sort(a.begin(), a.end(), ssort);
        int t = a[0][1];
        for (int i=1; i<a.size(); i++)
        {
            if (a[i][1] <= t) ans--;
            else t = a[i][1];
        }
        return ans;
    }
};