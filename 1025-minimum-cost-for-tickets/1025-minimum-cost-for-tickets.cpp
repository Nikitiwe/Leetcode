class Solution {
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        vector<int> ans(365, 10000000);
        vector<bool> isit(365, 0);
        for (int i=0; i!=d.size(); i++)
        {
            isit[d[i]-1]=1;
        }
        /*int l=d[0]-1, t=0;
        ans[l]=c[0];
        ans[min(l+6, 364)]=c[1];
        ans[min(l+29, 364)]=c[2];*/
        if (isit[0]==0) ans[0]=0;
        else ans[0]=min({c[0], c[1], c[2]});
        for (int i=0; i!=ans.size(); i++)
        {
            if (isit[i]==0)
            {
                if (i-1>=0) ans[i]=ans[i-1];
                /*if (i-7>=0) ans[i]=min(ans[i], ans[i-7]);
                if (i-30>=0) ans[i]=min(ans[i], ans[i-30]);*/
            }
            else
            {
                if (i-1>=0) ans[i]=min(ans[i], ans[i-1]+min({c[0], c[1], c[2]}));
                if (i-7>=0) ans[i]=min(ans[i], ans[i-7]+min(c[1], c[2]));
                else ans[i]=min(ans[i], c[1]);
                if (i-30>=0) ans[i]=min(ans[i], ans[i-30]+c[2]);
                else ans[i]=min(ans[i], c[2]);
            }
        }
        return ans[364];
    }
};