class Solution {
public:
    int minInsertions(string s) {
        int l=0, open=0, closed=0, ans=0;
        while (l<s.size())
        {
            if (s[l]=='(') {open++; l++;}
            else if (l<s.size()-1&&s[l]==')'&&s[l+1]==')') {closed++; l++; l++;}
            else {ans++; closed++; l++;}
            if (closed>0&&open>0)
            {
                open--;
                closed--;
            }
            if (closed>open)
            {
                ans++;
                closed--;
            }
        }
        ans+=open*2;
        return ans;
    }
};