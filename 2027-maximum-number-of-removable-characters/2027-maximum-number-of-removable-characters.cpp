class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& re) {
        int l=0, r=re.size(), m, ans=0;
        while (l<=r)
        {
            m=(l+r)/2;
            unordered_set<int> id;
            for (int i=0; i<m; i++) id.insert(re[i]);
            int a=0, b=0;
            while (a<s.size())
            {
                if (id.count(a)>0) a++;
                else
                {
                    if (s[a]==p[b])
                    {
                        a++;
                        b++;
                    }
                    else a++;
                }
                if (b==p.size()) break;
            }
            if (b==p.size())
            {
                ans=max(ans, m);
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};