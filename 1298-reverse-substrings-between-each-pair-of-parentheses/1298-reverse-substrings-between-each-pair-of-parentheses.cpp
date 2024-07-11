class Solution {
public:
    string reverseParentheses(string s) {
        while (find(s.begin(), s.end(),'(')!=s.end())
        {
            int i=0;
            while (s[i]!=')') i++;
            int j=i;
            while (s[j]!='(') j--;
            reverse(s.begin()+j+1, s.begin()+i);
            s[i]='.';
            s[j]='.';
        }
        string ans;
        for (int i=0; i!=s.size(); i++) if (s[i]!='.') ans+=s[i];
        return ans;
    }
}; 