class Solution {
public:
    int findComplement(int num) {
        long ans=0, add=1;
        while (num>0)
        {
            if (num%2==0) ans+=add;
            add*=2;
            num/=2;
        }
        return ans;
    }
};