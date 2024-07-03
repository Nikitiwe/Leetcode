class Solution {
public:
    int maxDepth(string s) {
        int ans=0, max=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='(') {max++; if (max>ans) ans=max;}
            else if (s[i]==')') {max--;}
        }
        return ans;
    }
};