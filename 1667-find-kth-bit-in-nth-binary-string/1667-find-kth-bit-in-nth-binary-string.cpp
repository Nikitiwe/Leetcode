class Solution {
public:
    char findKthBit(int n, int k) {
        int s=2;
        while (n>1)
        {
            s*=2;
            n--;
            if (s>k) break;
        }
        //s--;
        int a=0;
        while (s>0)
        {
            if (k==1)
            {
                //a++;
                break;
            }
            if (k==s/2)
            {
                a++;
                break;
            }
            else if (k>s/2)
            {
                k=s-k;
                a++;
            }
            s/=2;
        }
        if (a%2==0) return '0';
        else return '1';
    }
};