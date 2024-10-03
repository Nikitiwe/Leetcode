class Solution {
public:
    bool isItPossible(string s, string t) {
        vector<int> a(26, 0), b=a;
        for (int i=0; i!=s.size(); i++) a[s[i]-'a']++;
        for (int i=0; i!=t.size(); i++) b[t[i]-'a']++;
        int x=0, y=0;
        for (int i=0; i!=26; i++)
        {
            if (a[i]>0) x++;
            if (b[i]>0) y++;
        }
        if (abs(x-y)>=3) return 0;
        else if ((x-y)==2)
        {
            bool q=0, w=0;
            for (int i=0; i!=26; i++)
            {
                if (a[i]==1&&b[i]==0) q=1;
                if (b[i]>1&&a[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            else return 0;
        }
        else if ((y-x)==2)
        {
            bool q=0, w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]==1&&a[i]==0) q=1;
                if (a[i]>1&&b[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            else return 0;
        }
        else if ((x-y)==1)
        {
            bool q=0, w=0;
            for (int i=0; i!=26; i++)
            {
                if (a[i]>1&&b[i]==0) q=1;
                if (b[i]>1&&a[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                q=0; w=0;
                if (b[i]>1&&a[i]>0)
                {
                    q=1;
                    for (int j=0; j!=26; j++)
                    {
                        if (j!=i&&a[j]==1&&b[j]>0) w=1;
                    }
                    if (q==1&&w==1) return 1;
                }
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]>1&&a[i]==0) q=1;
                if (a[i]==1&&b[i]==0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (a[i]==1&&b[i]==0) q=1;
                if (b[i]==1&&a[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            else return 0;
        }
        else if ((y-x)==1)
        {
            bool q=0, w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]>1&&a[i]==0) q=1;
                if (a[i]>1&&b[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                q=0; w=0;
                if (a[i]>1&&b[i]>0)
                {
                    q=1;
                    for (int j=0; j!=26; j++)
                    {
                        if (j!=i&&b[j]==1&&a[j]>0) w=1;
                    }
                    if (q==1&&w==1) return 1;
                }
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (a[i]>1&&b[i]==0) q=1;
                if (b[i]==1&&a[i]==0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]==1&&a[i]==0) q=1;
                if (a[i]==1&&b[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            else return 0;
        }
        else if (y==x)
        {
            bool q=0, w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]>1&&a[i]>0) q=1;
                if (a[i]>1&&b[i]>0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]>1&&a[i]==0) q=1;
                if (a[i]>1&&b[i]==0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]==1&&a[i]==0) q=1;
                if (a[i]==1&&b[i]==0) w=1;
            }
            if (q==1&&w==1) return 1;
            q=0; w=0;
            for (int i=0; i!=26; i++)
            {
                if (b[i]>0&&a[i]>0) return 1;
            }
            if (q==1&&w==1) return 1;
            else return 0;
        }
        return 0;
    }
};