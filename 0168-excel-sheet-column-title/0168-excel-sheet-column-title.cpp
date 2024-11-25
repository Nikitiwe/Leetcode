class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n>0)
        {
            ans+='A'+(n-1)%26;
            n--;
            n/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};