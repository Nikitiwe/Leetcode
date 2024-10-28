class Solution {
public:
    int maxDistance(vector<int>& c) {
        int ans=0, n=c.size();
        for (int i=n-1; i>0; i--)
        {
            if (c[0]!=c[i])
            {
                ans=max(ans, i);
                break;
            }
        }
        for (int i=0; i<n-1; i++)
        {
            if (c[n-1]!=c[i])
            {
                ans=max(ans, n-i-1);
                break;
            }
        }
        return ans;
    }
};