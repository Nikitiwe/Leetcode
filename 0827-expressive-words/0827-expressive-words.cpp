class Solution {
public:
    int expressiveWords(string s, vector<string>& w) {
        vector<char> sc;
        vector<int> sn;
        int t=1;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]==s[i-1])
            {
                t++;
            }
            else
            {
                sc.push_back(s[i-1]);
                sn.push_back(t);
                t=1;
            }
        }
        sc.push_back(s.back());
        sn.push_back(t);
        int ans=0;
        for (int k=0; k!=w.size(); k++)
        {
            vector<char> c;
            vector<int> n;
            t=1;
            for (int i=1; i<w[k].size(); i++)
            {
                if (w[k][i]==w[k][i-1])
                {
                    t++;
                }
                else
                {
                    c.push_back(w[k][i-1]);
                    n.push_back(t);
                    t=1;
                }
            }
            c.push_back(w[k].back());
            n.push_back(t);
            bool isit=1;
            if (c.size()==sc.size()) for (int i=0; i!=c.size(); i++)
            {
                if (c[i]==sc[i])
                {
                    if (n[i]>sn[i]||(n[i]==1&&sn[i]==2))
                    {
                        isit=0;
                        break;
                    }
                }
                else
                {
                    isit=0;
                    break;
                }
            }
            else isit=0;
            if (isit==1) ans++;
        }
        return ans;
    }
};