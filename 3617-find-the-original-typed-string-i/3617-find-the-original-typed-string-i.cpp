class Solution {
public:
    int possibleStringCount(string s) {
        s+=' ';
        int ans=0, t=1;
        char c=s[0];
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==c) t++;
            else
            {
                c=s[i];
                ans+=t-1;
                t=1;
            }
        }
        return ans;
    }
};