class Solution {
public:
    bool checkOnesSegment(string s) {
        s+='0';
        int c=0;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]=='1'&&s[i+1]=='0') c++;
        }
        if (c>1) return 0;
        else return 1;
    }
};