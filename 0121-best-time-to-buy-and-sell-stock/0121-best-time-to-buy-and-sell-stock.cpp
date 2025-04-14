class Solution {
public:
    int maxProfit(vector<int>& p) {
        int m=p[0], ans=0;
        for (int i=1; i<p.size(); i++)
        {
            if (p[i] > m) ans = max(p[i]-m, ans);
            else m = p[i];
        }
        return ans;
    }
};