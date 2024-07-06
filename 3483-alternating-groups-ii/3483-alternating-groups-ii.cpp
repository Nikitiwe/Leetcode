class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0, n=colors.size(), isit=0;
        vector<bool> diff(n, 0);
        for (int i=0; i!=n; i++)
        {
            if (colors[i]+colors[(i+1)%n]==1) diff[i]=1;
        }
        for (int i=0; i!=n; i++)
        {
            if (isit==1)
            {
                if (diff[(i+k-2)%n]==1) ans++;
                else isit=0;
            }
            else
            {
                isit=1;
                for (int j=i; j!=i+k-1; j++)
                {
                    if (diff[j%n]==0) {isit=0; break;}
                }
                if (isit==1) ans++;
            }
        }
        return ans;
    }
};
