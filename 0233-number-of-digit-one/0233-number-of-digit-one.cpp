class Solution {
public:
    int countDigitOne(int n) {
        string a;
        int ans=0, c=0, m=n/100000;
        for (int i=0; i<m; i++)
        {
            a=to_string(i);
            for (int j=0; j!=a.size(); j++)
            {
                if (a[j]=='1') ans=ans+100000;
            }
            ans=ans+50000;
        }
        for (int i=m*100000; i<=n; i++)
        {
            a=to_string(i);
            for (int j=0; j!=a.size(); j++)
            {
                if (a[j]=='1') ans++;
            }
        }
        return ans;
    }
}; // единиц в числах от 1 до 99999 ровно 50000 штук