class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        unordered_map<string, int> n;
        int ans=0;
        for (int i=0; i!=m.size(); i++)
        {
            string t;
            for (int j=0; j!=m[i].size(); j++)
            {
                t+=m[i][j];
                m[i][j]=1-m[i][j];
            }
            n[t]++;
            ans=max(ans, n[t]);
            t="";
            for (int j=0; j!=m[i].size(); j++)
            {
                t+=m[i][j];
            }
            n[t]++;
            ans=max(ans, n[t]);
        }
        return ans;
    }
};