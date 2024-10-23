class Solution {
public:
    bool checkString(string s) {
        if (s.size()==1) return 1;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]=='b'&&s[i+1]=='a') return 0;
        }
        return 1;
    }
};