class Solution {
public:
    int monkeyMove(int n) {
        long ans=1, add=2, p=0;
        while (0<n)
        {
            if (n%2==0)
            {
                add*=add;
                add%=1000000007;
                n/=2;
            }
            else
            {
                ans*=add;
                add*=add;
                add%=1000000007;
                n/=2;
                ans%=1000000007;
            }
        }
        ans+=1000000005;
        ans%=1000000007;
        return ans;
    }
};