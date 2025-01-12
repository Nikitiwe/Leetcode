class Solution {
public:
    bool canBeValid(string s, string loc) {
        if (s.size()%2==1) return 0;
        int l=0, r=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (loc[i]=='1')
            {
                if (s[i]=='(') l++;
                else r++;
            }
            else l++;
            if (r>l) return 0;
        }
        l=0; r=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (loc[i]=='1')
            {
                if (s[i]==')') r++;
                else l++;
            }
            else r++;
            if (l>r) return 0;
        }
        return 1;
    }
};