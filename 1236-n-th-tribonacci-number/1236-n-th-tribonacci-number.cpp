class Solution {
public:
    int tribonacci(int n) {
        if (n<=1) return n;
        else if (n==2) return 1;
        int a=0, b=0, c=1, s;
        while (n>1)
        {
            s=a+b+c;
            a=b;
            b=c;
            c=s;
            n--;
        }
        return c;
    }
};