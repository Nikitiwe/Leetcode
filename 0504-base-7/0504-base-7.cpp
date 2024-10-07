class Solution {
public:
    string convertToBase7(int n) {
        if (n==0) return "0";
        string ans, sig;
        if (n<0)
        {
            sig+='-';
            n*=-1;
        }
        while (n>0)
        {
            ans+=to_string(n%7);
            n/=7;
        }
        ans+=sig;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};