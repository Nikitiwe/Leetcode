class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        int ans=0, l=0;
        for (int i=0; i!=r.size(); i++)
        {
            l=max(l, min(r[i][0], r[i][1]));
        }
        for (int i=0; i!=r.size(); i++)
        {
            if (r[i][0]>=l&&r[i][1]>=l) ans++;
        }
        return ans;
    }
};