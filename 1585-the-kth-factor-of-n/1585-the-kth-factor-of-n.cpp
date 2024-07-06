class Solution {
public:
    int kthFactor(int n, int k) {
        int ans=0;
        for (int i=1; i<=(int)sqrt(n); i++)
        {
            if (n%i==0) ans++;
            if (ans==k) return i;
        }
        if((int)sqrt(n)*(int)sqrt(n)!=n) {
        for (int i=(int)sqrt(n); i>0; i--)
        {
            if (n%i==0) ans++;
            if (ans==k) return n/i;
        } }
        else
        for (int i=(int)sqrt(n)-1; i>0; i--)
        {
            if (n%i==0) ans++;
            if (ans==k) return n/i;
        }
        return -1;
    }
};