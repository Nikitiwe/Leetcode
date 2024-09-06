class Solution {
public:
    int integerReplacement(int m) {
        long n=m;
        int ans=0;
        while (n>1)
        {
            if (n==3) n--;
            else if (n%2==0) n/=2;
            else
            {
                if ((n+1)%4==0) n++;
                else n--;
            }
            ans++;
        }
        return ans;
    }
};