class Solution {
public:
    int integerReplacement(int n) {
        int ans=0;
        while (n>1)
        {
            if (n==3) n--;
            else if (n%2==0) n/=2;
            else
            {
                if ((n-1)%4==0) n/=4;
                else
                {
                    n/=4;
                    n++;
                }
                ans++;
                ans++;
            }
            ans++;
        }
        return ans;
    }
};