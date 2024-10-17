class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int c=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (c>0) ans+=s[i];
            if (s[i]=='(') c++;
            else c--;
            if (c==0) ans.pop_back();
        }
        return ans;
    }
};