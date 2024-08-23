class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=1;
        if (n%2==1)
        {
            for (int i=2; i*i<n*2; i=i+2)
            {
                if ((2*n)%i==0) ans++;
            }
            for (int i=3; i*i<n*2; i=i+2)
            {
                if (n%i==0) ans++;
            }
        }
        else
        {
            for (int i=4; i*i<n*2; i=i+2)
            {
                if ((2*n)%i==0&&((2*n)/i)%2==1) ans++;
            }
            for (int i=3; i*i<n*2; i=i+2)
            {
                if (n%i==0) ans++;
            }
        }
        return ans;
    }
};