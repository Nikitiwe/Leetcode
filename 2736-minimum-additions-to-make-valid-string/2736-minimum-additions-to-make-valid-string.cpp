class Solution {
public:
    int addMinimum(string s) {
        int l=0, w=1, ans=0;
        while (l<s.size())
        {
            if (w==1)
            {
                if (s[l]=='b') {ans++; w=3;}
                else if (s[l]=='c') ans+=2;
                else w=2;
            }
            else if (w==2)
            {
                if (s[l]=='c') {ans++; w=1;}
                else if (s[l]=='a') {ans+=2; w=2;}
                else w=3;
            }
            else
            {
                if (s[l]=='a') {ans++; w=2;}
                else if (s[l]=='b') {ans+=2; w=3;}
                else w=1;
            }
            l++;
        }
        if (s[s.size()-1]=='a') ans+=2;
        else if (s[s.size()-1]=='b') ans++;
        return ans;
    }
};