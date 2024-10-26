class Solution {
public:
    int alternateDigitSum(int n) {
        int ans=0;
        string s=to_string(n);
        if (s.size()%2==1) while (n>0)
        {
            ans+=n%10;
            n/=10;
            ans-=n%10;
            n/=10;
        }
        else while (n>0)
        {
            ans-=n%10;
            n/=10;
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
};