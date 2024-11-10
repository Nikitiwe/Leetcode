class Solution {
public:
    string thousandSeparator(int n) {
        if (n==0) return "0";
        string ans;
        while (n!=0)
        {
            for (int i=0; i!=3; i++)
            {
                ans+=to_string(n%10);
                n/=10;
                if (n==0) break;
            }
            if (n!=0) ans+='.';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};