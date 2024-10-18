class Solution {
public:
    int countPoints(string r) {
        int a=0, b=0, c=0, ans=0;
        for (int i=0; i<=9; i++)
        {
            a=0; b=0; c=0;
            for (int j=1; j<r.size(); j+=2)
            {
                if (r[j]-'0'==i)
                {
                    if (r[j-1]=='R') a=1;
                    else if (r[j-1]=='G') b=1;
                    else c=1;
                }
            }
            if (a+b+c==3) ans++;
        }
        return ans;
    }
};