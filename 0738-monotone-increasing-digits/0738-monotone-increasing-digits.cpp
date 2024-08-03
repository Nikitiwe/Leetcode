class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n), ans;
        ans+=s[0];
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]>=ans[i-1]) ans+=s[i];
            else
            {
                while (ans.size()>1&&ans[ans.size()-1]==ans[ans.size()-2]) ans.pop_back();
                ans.pop_back();
                ans+=to_string((s[ans.size()]-'0')-1);
                break;
            }
        }
        while (ans.size()<s.size()) ans+='9';
        return stoi(ans);
    }
};