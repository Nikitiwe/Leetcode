class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int> ans(p.size(), 0);
        int t=0;
        for (int i=0; i<p.size(); i++)
        {
            vector<int> mip(p.size(), 0);
            int mi=1000;
            for (int j=i; j<p.size(); j++)
            {
                mi=min(mi, p[j]);
                mip[j]=mi;
            }
            int ma=0;
            for (int j=i+1; j<p.size(); j++)
            {
                ma=p[j];
                if (i>1) ans[j]=max(ans[j], ma-mip[j-1]+ans[i-2]);
                else ans[j]=max(ans[j], ma-mip[j-1]);
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};