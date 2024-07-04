class Solution {
public:
    int minAddToMakeValid(string s) {
        int l=0, r=0, temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==')') {temp++; if (temp>l) l=temp;}
            else temp--;
        }
        temp=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='(') {temp++; if (temp>r) r=temp;}
            else temp--;
        }
        return l+r;
    }
};