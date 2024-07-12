class Solution {
public:
    int numSteps(string s) {
        int ans=0, add=0;
        while (s.size()>1)
        {
            if (s[s.size()-1]=='0'&&add==0)
            {
                ans++;
                s.erase(s.size()-1);
                if (s.size()==0) break;
            }
            else if (s[s.size()-1]=='0'&&add==1)
            {
                s[s.size()-1]='1';
                add=0;
            }
            else if (s[s.size()-1]=='1'&&add==0)
            {
                s.erase(s.size()-1);
                ans++;
                ans++;
                add=1;
            }
            else
            {
                ans++;
                s.erase(s.size()-1);
                add=1;
                if (s.size()==0) break;
            }
        }
        if (add==1) ans++;
        return ans;
    }
};