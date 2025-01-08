class Solution {
public:
    int minOperations(string s) {
        int t=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0)
            {
                if (s[i]=='1') t++;
            }
            else if (s[i]=='0') t++;
        }
        int ans=t;
        t=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0)
            {
                if (s[i]=='0') t++;
            }
            else if (s[i]=='1') t++;
        }
        return min(ans, t);
    }
};