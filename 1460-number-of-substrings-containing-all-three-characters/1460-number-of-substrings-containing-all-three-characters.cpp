class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> a(s.size()+1, 0), b = a, c = a;
        for (int i=0; i!=s.size(); i++)
        {
            a[i+1] += a[i];
            b[i+1] += b[i];
            c[i+1] += c[i];
            if (s[i] == 'a') a[i+1]++;
            else if (s[i] == 'b') b[i+1]++;
            else c[i+1]++;
        }
        int ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            int l=0, r=i, m;
            int add = 0;
            while (l <= r)
            {
                bool isit = 1;
                m = (l+r)/2;
                if (a[i+1] - a[m] == 0 || b[i+1] - b[m] == 0 || c[i+1] - c[m] == 0 ) isit = 0;
                if (isit == 1)
                {
                    l = m+1;
                    add = max(add, m+1);
                }
                else r = m-1;
            }
            ans += add;
        }
        return ans;
    }
};