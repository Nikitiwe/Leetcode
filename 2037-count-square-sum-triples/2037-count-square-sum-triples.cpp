class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for (int i=5; i<=n; i++)
        {
            int ii=i*i;
            for (int j=2; j<i; j++)
            {
                int t=sqrt(ii-j*j);
                if (t*t+j*j==ii) ans++;
            }
        }
        return ans;
    }
};