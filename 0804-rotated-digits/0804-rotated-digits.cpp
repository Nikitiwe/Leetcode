class Solution {
public:
    int rotatedDigits(int n) {
        string a, b;
        int ans=0, f;
        for (int i=1; i<=n; i++)
        {
            a=to_string(i);
            b=a;
            f=1;
            for (int j=0; j!=b.size(); j++)
            {
                if (b[j]=='2') b[j]='5';
                else if (b[j]=='5') b[j]='2';
                else if (b[j]=='9') b[j]='6';
                else if (b[j]=='6') b[j]='9';
                else if (b[j]=='3'||b[j]=='7'||b[j]=='4') {f=0; break;}
            }
            if (f==1&&a!=b) ans++;
            a.clear();
            b.clear();
        }
        return ans;
    }
};