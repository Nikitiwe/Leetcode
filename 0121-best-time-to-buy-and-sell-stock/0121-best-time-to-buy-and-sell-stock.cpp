class Solution {
public:
    int maxProfit(vector<int>& p) {
        int m=p[0], ans=0;
        for (int i=0; i!=p.size(); i++)
        {
            ans=max(p[i]-m, ans);
            m=min(m, p[i]);
        }
        return ans;
    }
};