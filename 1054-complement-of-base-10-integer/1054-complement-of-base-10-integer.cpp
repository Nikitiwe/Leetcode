class Solution {
public:
    int bitwiseComplement(int n) {
        //if (n==2) retutrn 1;
        int a=2;
        while(a<=n) a*=2;
        return a-n-1;
    }
};