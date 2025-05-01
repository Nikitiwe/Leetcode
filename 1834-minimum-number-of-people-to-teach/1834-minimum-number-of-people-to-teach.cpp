class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& ff) {
        int ans = 1000;
        vector<unordered_set<int>> s(l.size()+1, unordered_set<int>());
        for (int i=0; i!=l.size(); i++)
        {
            for (int j=0; j<l[i].size(); j++) s[i+1].insert(l[i][j]);
        }
        vector<vector<int>> f;
        for (int i=0; i!=ff.size(); i++)
        {
            bool ise = 0;
            for (int k = 1; k<=n; k++)
            {
                if (s[ff[i][0]].count(k) != 0 && s[ff[i][1]].count(k) != 0)
                {
                    ise = 1;
                    break;
                }
            }
            if (ise == 0) f.push_back(ff[i]);
        }
        for (int k = 1; k<=n; k++)
        {
            int c = 0;
            vector<bool> isit(l.size()+1, 0);
            for (int i=0; i<f.size(); i++)
            {
                if (s[f[i][0]].count(k) == 0 && isit[f[i][0]] == 0)
                {
                    c++;
                    isit[f[i][0]] = 1;
                }
                if (s[f[i][1]].count(k) == 0 && isit[f[i][1]] == 0)
                {
                    c++;
                    isit[f[i][1]] = 1;
                }
            }
            ans = min(ans, c);
        }
        return ans;
    }
};