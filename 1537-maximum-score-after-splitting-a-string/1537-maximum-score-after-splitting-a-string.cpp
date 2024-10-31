class Solution {
public:
    int maxScore(string s) {
        int sum=0, ans=0, t=0;
        for (int i=0; i!=s.size(); i++) sum+=s[i]-'0';
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]=='0')
            {
                t++;
            }
            else
            {
                sum--;
            }
            ans=max(t+sum, ans);
        }
        return ans;
    }
};