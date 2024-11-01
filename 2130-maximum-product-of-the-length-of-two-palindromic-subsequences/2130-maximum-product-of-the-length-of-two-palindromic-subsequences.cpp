class Solution {
public:
    int maxProduct(string s) {
        int n=s.size(), a=1, ans=1;
        for (int i=0; i!=n; i++) a*=3;
        a--;
        for (int k=1; k<=a; k++)
        {
            string x, y;
            int b=k, l=0;
            while (b>0)
            {
                if (b%3==1)
                {
                    x+=s[l];
                }
                else if (b%3==2)
                {
                    y+=s[l];
                }
                l++;
                b/=3;
            }
            if (x.size()>0&&y.size()>0&&(int)x.size()*(int)y.size()>ans)
            {
                bool isit=1;
                for (int i=0; i<x.size()/2; i++)
                {
                    if (x[i]!=x[x.size()-1-i])
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) for (int i=0; i<y.size()/2; i++)
                {
                    if (y[i]!=y[y.size()-1-i])
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) ans=max(ans, (int)x.size()*(int)y.size());
            }
        }
        return ans;
    }
};