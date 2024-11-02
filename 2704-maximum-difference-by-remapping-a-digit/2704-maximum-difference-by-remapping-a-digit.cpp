class Solution {
public:
    int minMaxDifference(int n) {
        string s=to_string(n);
        int ans, l=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!='9')
            {
                l=i;
                break;
            }
        }
        for (int i=s.size()-1; i>=l; i--)
        {
            if (s[i]==s[l])
            {
                s[i]='9';
            }
        }
        ans=stoi(s);
        s=to_string(n);
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]==s[0])
            {
                s[i]='0';
            }
        }
        ans-=stoi(s);
        return ans;
    }
};