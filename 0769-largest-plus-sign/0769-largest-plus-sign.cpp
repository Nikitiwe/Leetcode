class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        unordered_set<int> m;
        int k=501;
        for (int i=0; i!=mines.size(); i++) m.insert(mines[i][1]*k+mines[i][0]);
        int ans=0;
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=n; j++)
            {
                if (i<ans||j<ans||n-i<ans||n-j<ans) continue;
                if (m.count(k*i+j)==0)
                {
                    int l=0, t=0;
                    while (i+l+1<n&&m.count(k*(i+l+1)+j)==0) l++;
                    t=l; l=0;
                    if (t<ans) continue;
                    while (j+l+1<n&&l<t&&m.count(k*(i)+j+l+1)==0) l++;
                    t=min(t, l); l=0;
                    if (t<ans) continue;
                    while (i-l-1>=0&&l<t&&m.count(k*(i-l-1)+j)==0) l++;
                    t=min(t, l); l=0;
                    if (t<ans) continue;
                    while (j-l-1>=0&&l<t&&m.count(k*(i)+j-l-1)==0) l++;
                    t=min(t, l);
                    ans=max(ans, t+1);
                }
            }
        }
        return ans;
    }
};