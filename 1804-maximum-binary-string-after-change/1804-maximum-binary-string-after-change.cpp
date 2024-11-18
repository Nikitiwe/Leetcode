class Solution {
public:
    string maximumBinaryString(string s) {
        int l=1;
        for (int i=0; i<s.size()-1; i++)
        {
            if (s[i]=='0'&&s[i+1]=='0') s[i]='1';
            else if (s[i]=='0'&&s[i+1]=='1')
            {
                l=max(i+1, l);
                while (l+1<s.size()&&s[l]=='1') l++;
                if (l<s.size())
                {
                    swap(s[i+1], s[l]);
                }
                if (s[i+1]=='0') s[i]='1';
            }
        }
        return s;
    }
};