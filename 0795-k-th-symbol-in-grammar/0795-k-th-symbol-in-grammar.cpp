class Solution {
public:
    int kthGrammar(int n, int k) {
        int a=1, temp=0;
        while (k>1)
        {
            while (2*a<k) a*=2;
            k-=a;
            temp++;
            a=1;
        }
        return temp%2;
    }
};