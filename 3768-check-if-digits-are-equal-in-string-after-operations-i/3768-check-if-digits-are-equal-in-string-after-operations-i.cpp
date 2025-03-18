class Solution {
public:
    bool hasSameDigits(string s) {
        string t;
        while (s.size() > 2)
        {
            t = "";
            for (int i=0; i<s.size()-1; i++)
            {
                t += to_string((s[i]-'0'+s[i+1]-'0') %10);
            }
            s = t;
        }
        if (s[0] == s[1]) return 1;
        else return 0;
    }
};