class Solution {
public:
    bool checkString(string s) {
        if (s.size()==1) return 1;
        int i=0;
        while (i<s.size()-1)
        {
            if (s[i]=='a') i++;
            else if (s[i+1]=='a') return 0;
            else i++;
            
        }
        return 1;
    }
};