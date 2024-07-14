class Solution {
public:
    bool isValid(string s) {
        if (s.size()%3!=0) return 0;
        string a=s, b;
        int n;
        while (a.size()>0)
        {
            n=a.size();
            for (int i=0; i!=a.size(); i++)
            {
                b+=a[i];
                if (b.size()>2&&b[b.size()-1]=='c'&&b[b.size()-2]=='b'&&b[b.size()-3]=='a')
                {
                    b.erase(b.end()-1);
                    b.erase(b.end()-1);
                    b.erase(b.end()-1);
                }
            }
            if (n==b.size()) return 0;
            a=b;
            b.clear();
        }
        return 1;
    }
};