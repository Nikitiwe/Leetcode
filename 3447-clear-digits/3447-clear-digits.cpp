class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int t=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                t++;
            }
            else
            {
                if (t>0) t--;
                else ans+=s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};