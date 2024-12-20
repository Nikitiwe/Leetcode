class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& g, int k) {
        unordered_map<int, int> prev, next, zero, ans;
        int m=g.size(), n=g[0].size();
        prev[0]=g[0][0];
        ans[0]=g[0][0];
        ans[100*(m-1)+n-1]=k;
        while (1)
        {
            int a=0;
            for (auto i=prev.begin(); i!=prev.end(); i++)
            {
                int x=i->first/100, y=i->first%100, l=i->second;
                if (x>0)
                {
                    if (ans.count(100*(x-1)+y)==0||ans[100*(x-1)+y]>l+g[x-1][y])
                    {
                        a++;
                        ans[100*(x-1)+y]=l+g[x-1][y];
                        next[100*(x-1)+y]=l+g[x-1][y];
                    }
                }
                if (y>0)
                {
                    if (ans.count(100*(x)+y-1)==0||ans[100*(x)+y-1]>l+g[x][y-1])
                    {
                        a++;
                        ans[100*(x)+y-1]=l+g[x][y-1];
                        next[100*(x)+y-1]=l+g[x][y-1];
                    }
                }
                if (x<m-1)
                {
                    if (ans.count(100*(x+1)+y)==0||ans[100*(x+1)+y]>l+g[x+1][y])
                    {
                        a++;
                        ans[100*(x+1)+y]=l+g[x+1][y];
                        next[100*(x+1)+y]=l+g[x+1][y];
                    }
                }
                if (y<n-1)
                {
                    if (ans.count(100*(x)+y+1)==0||ans[100*(x)+y+1]>l+g[x][y+1])
                    {
                        a++;
                        ans[100*(x)+y+1]=l+g[x][y+1];
                        next[100*(x)+y+1]=l+g[x][y+1];
                    }
                }
            }
            prev=next;
            next=zero;
            if (ans[100*(m-1)+n-1]<k) return 1;
            if (a==0) break;
        }
        return 0;
    }
};