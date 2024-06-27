class Solution {
public:
    int countHomogenous(string s) {
        int t=1, ans=1;
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i-1]==s[i]) t++;
            else t=1; 
            ans=(ans+t)%1000000007;
        }
        return ans;
    }
};