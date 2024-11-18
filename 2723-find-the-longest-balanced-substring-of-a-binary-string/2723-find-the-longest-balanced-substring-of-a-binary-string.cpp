class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]=='0'&&s[i+1]=='1')
            {
                int l=1;
                while (i-l>=0&&i+1+l<s.size()&&s[i-l]=='0'&&s[i+1+l]=='1') l++;
                ans=max(ans, l);
            }
        }
        return 2*ans;
    }
};