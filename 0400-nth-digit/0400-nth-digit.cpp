class Solution {
public:
    int findNthDigit(int n) {
        long a=9, m=1, r=1;
        while (n>a*r)
        {
            n-=a*r;
            a*=10;
            m*=10;
            r++;
        }
        n--;
        string s=to_string(m+n/r);
        return s[n%r]-'0';
    }
};