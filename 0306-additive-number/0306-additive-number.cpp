class Solution {
public:
    bool isAdditiveNumber(string s) {
        string a;
        for (int i=0; i<min(18, (int)s.size()); i++)
        {
            a+=s[i];
            if (a.size()>1&&a[0]=='0') break;
            string b;
            for (int j=i+1; j<min(i+18, (int)s.size()); j++)
            {
                b+=s[j];
                if (b.size()>1&&b[0]=='0') break;
                string x=a, y=b, z;
                int l=j+1;
                while (l<s.size())
                {
                    z+=s[l];
                    if (z.size()>1&&z[0]=='0') break;
                    l++;
                    if (stoll(z)>stoll(x)+stoll(y)) break;
                    else if (stoll(z)==stoll(x)+stoll(y))
                    {
                        if (l==s.size()) return 1;
                        x=y;
                        y=z;
                        z="";
                    }
                }
            }
        }
        return 0;
    }
};