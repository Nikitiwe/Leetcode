class Solution {
public:
    bool f(string &t)
    {
        if (t.size() < 2) return 0;
        if (t[0] != '$') return 0;
        for (int i=1; i<t.size(); i++) if (t[i] < '0' || t[i] > '9') return 0;
        return 1;
    }

    string discountPrices(string s, int d) {
        string ans;
        string t;
        s += " ";
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] != ' ') t += s[i];
            else
            {
                if (f(t) == 1)
                {
                    double a = 0;
                    for (int i=1; i<t.size(); i++)
                    {
                        a *= 10;
                        a += t[i] - '0';
                    }
                    a /= 100;
                    a *= (100-d);
                    t = '$' + format("{:.2f}", a);
                }
                if (ans.size() != 0) ans += " ";
                ans += t;
                t = "";
            }
        }
        return ans;
    }
};