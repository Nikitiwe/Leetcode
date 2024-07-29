class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0, i;
        string a;
        while (1)
        {
            a=s;
            i=0;
            while (i<s.size()-1)
            {
                if (s[i]=='0'&&s[i+1]=='1') {s[i]='1'; s[i+1]='0'; i=i+2;}
                else i++;
            }
            if (s!=a) ans++;
            else return ans;
        }
    }
};