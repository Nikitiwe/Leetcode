class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> isit(s.size(), 1);
        string ans;
        int delta=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='(') {delta++;}
            else if (s[i]==')')
            {
                if (delta==0) isit[i]=0;
                else {delta--;}
            }
        }
        delta=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]==')') {delta++;}
            else if (s[i]=='(')
            {
                if (delta==0) isit[i]=0;
                else {delta--;}
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            if (isit[i]==1) ans+=s[i];
        }
        return ans;
    }
}; // Memory Limit Exceeded 56/62 testcases passed
// why tf x=+y is faster than x=x+y