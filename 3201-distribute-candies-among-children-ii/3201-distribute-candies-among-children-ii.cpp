class Solution {
public:
    long long distributeCandies(int nn, int limit) {
        long long n=nn, l=limit+1;
        if (n>3*limit) return 0;
        long long a=(n+1)*(n)/2+(n+1);
        long long b=0;
        if (n>limit) b=(n-l+1)*(n-l)/2+(n-l+1);
        long long c=0;
        if (n>2*limit) c=(n-l*2+1)*(n-l*2)/2+(n-l*2+1);
        return a-3*b+3*c;
    }
};