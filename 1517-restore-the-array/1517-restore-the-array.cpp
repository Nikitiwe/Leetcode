class Solution {
public:
    int numberOfArrays(string s, int m) {
        if (s[0]=='0') return 0;
        vector<int> ans(s.size()+1, 0);
        ans[0]=1;
        for (int i=0; i<s.size(); i++)
        {
            for (int j=max(i-10, 0); j<=i; j++)
            {
                long t=0, tt;
                bool isit=1;
                for (int k=j; k<=i; k++)
                {
                    tt=t;
                    t*=10;
                    t+=s[k]-'0';
                    if (tt==t)
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1&&t<=m)
                {
                    ans[i+1]+=ans[j];
                    ans[i+1]%=1000000007;
                }
            }
        }
        return ans.back();
    }
};