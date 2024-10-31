class Solution {
public:
    bool isThree(int n) {
        if (n==1) return 0;
        int a=sqrt(n);
        if (a*a==n)
        {
            n=sqrt(n);
            for (int i=2; i<=sqrt(n); i++)
            {
                if (n%i==0) return 0;
            }
            return 1;
        }
        else return 0;
    }
};