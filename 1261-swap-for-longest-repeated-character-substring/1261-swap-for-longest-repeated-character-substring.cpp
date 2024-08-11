class Solution {
public:
    int maxRepOpt1(string text) {
        int l=0, r=0, ans=0, sum=0, temp=0, diff=0, gans=1;
        for (int i='a'; i<='z'; i++)
        {
            l=0; r=0; sum=0; temp=0; diff=0; ans=0;
            for (int j=0; j!=text.size(); j++) if (text[j]==i) sum++;
            if (text[r]==i) temp++;
            else diff++;
            if (sum>gans) while (r<text.size())
            {
                if (diff<=1)
                {
                    r++;
                    if (r==text.size()) break;
                    if (text[r]==i) {temp++; ans=max(ans, temp);}
                    else diff++;
                }
                else
                {
                    if (text[l]==i) temp--;
                    else diff--;
                    l++;
                }
            }
            if (sum>ans) ans++;
            gans=max(gans, ans);
        }
        return gans;
    }
};