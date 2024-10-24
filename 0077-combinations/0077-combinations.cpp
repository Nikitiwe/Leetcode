class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> m, next;
        vector<int> tt(1, 0);
        for (int i=1; i<=n; i++)
        {
            tt[0]=i;
            m.push_back(tt);
        }
        for (int i=2; i<=k; i++)
        {
            for (int j=0; j!=m.size(); j++)
            {
                vector<int> t=m[j];
                t.push_back(0);
                for (int a=t[i-2]+1; a<=n; a++)
                {
                    t[i-1]=a;
                    next.push_back(t);
                }
            }
            m=next;
            next.clear();
        }
        return m;
    }
};