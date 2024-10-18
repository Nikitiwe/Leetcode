class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        int ans=0, l=0;
        for (int i=0; i!=r.size(); i++)
        {
            r[i][0]=min(r[i][0], r[i][1]);
            l=max(l, r[i][0]);
        }
        for (int i=0; i!=r.size(); i++)
        {
            if (r[i][0]>=l) ans++;
        }
        return ans;
    }
};