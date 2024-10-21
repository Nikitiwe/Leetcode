class Solution {
public:
    int prefixCount(vector<string>& w, string p) {
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            bool isit=1;
            if (w[i].size()<p.size()) isit=0;
            else for (int j=0; j<p.size(); j++)
            {
                if (w[i][j]!=p[j])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans++;
        }
        return ans;
    }
};