class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> m, next;
        for (int i=1; i<=n; i++)
        {
            vector<int> t;
            t.push_back(i);
            m.push_back(t);
        }
        for (int i=2; i<=k; i++)
        {
            for (int j=0; j!=m.size(); j++)
            {
                for (int a=m[j][m[j].size()-1]+1; a<=n; a++)
                {
                    vector<int> t=m[j];
                    t.push_back(a);
                    next.push_back(t);
                }
            }
            m=next;
            next.clear();
        }
        return m;
    }
};