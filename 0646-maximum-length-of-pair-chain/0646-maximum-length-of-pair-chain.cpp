class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        vector<int> ans(p.size(), 1);
        int t=1;
        for (int i=1; i<p.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                if (p[j][1]<p[i][0])
                {
                    ans[i]=max(ans[i], ans[j]+1);
                    t=max(ans[i], t);
                }
            }
        }
        return  t;
    }
};