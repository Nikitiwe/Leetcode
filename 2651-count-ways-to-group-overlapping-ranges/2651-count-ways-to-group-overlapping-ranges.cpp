class Solution {
public:
    int countWays(vector<vector<int>>& r) {
        sort(r.begin(), r.end());
        int t=r[0][1], g=1;
        for (int i=0; i!=r.size(); i++)
        {
            if (r[i][0]>t) g++;
            t=max(t, r[i][1]);
        }
        long long ans=1;
        while (g>20)
        {
            ans*=1048576;
            ans%=1000000007;
            g=g-20;
        }
        while (g>0)
        {
            ans*=2;
            ans%=1000000007;
            g--;
        }
        return ans;
    }
};