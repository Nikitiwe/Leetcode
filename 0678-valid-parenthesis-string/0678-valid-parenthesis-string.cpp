class Solution {
public:
    bool checkValidString(string s) {
        int o=0, c=0, j=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='(') o++;
            else if (s[i]==')') c++;
            else j++;
            while (c>o&&j>0) {o++; j--;}
            if (c>o+j) return 0;
        }
        if (o>c+j) return 0;
        o=0; c=0; j=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='(') o++;
            else if (s[i]==')') c++;
            else j++;
            while (o>c&&j>0) {c++; j--;}
            if (o>c+j) return 0;
        }
        if (c>o+j) return 0;
        return 1;
    }
};