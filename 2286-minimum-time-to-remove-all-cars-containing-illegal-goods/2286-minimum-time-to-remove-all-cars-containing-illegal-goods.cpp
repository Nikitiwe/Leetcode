class Solution {
public:
    int minimumTime(string s) {
        if (s == "1") return 1;
        if (s == "0") return 0;
        vector<int> l(s.size(), 0), r = l;
        for (int i=0; i!=l.size(); i++) l[i] = i + 1;
        for (int i=0; i!=l.size(); i++)
        {
            if (s[i] == '0')
            {
                if (i > 0) l[i] = l[i-1];
                else l[i] = 0;
            }
            else
            {
                if (i > 0) l[i] = min(l[i], l[i-1] + 2);
            }
        }
        for (int i=0; i!=l.size(); i++) r[r.size() - 1 - i] = i + 1;
        for (int i=r.size(); i>=0; i--)
        {
            if (s[i] == '0')
            {
                if (i+1 < r.size()) r[i] = r[i+1];
                else r[i] = 0;
            }
            else
            {
                if (i+1 < r.size()) r[i] = min(r[i], r[i+1] + 2);
            }
        }
        int ans = 1000000000;
        for (int i=0; i+1<l.size(); i++)
        {
            ans = min(l[i] + r[i+1], ans);
        }
        return ans;
    }
};