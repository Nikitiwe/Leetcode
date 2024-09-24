class Solution {
public:
    bool canBeValid(string s, string arr) {
        if (s.size()%2==1) return 0;
        int a=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]==')'&&arr[i]=='1') a--;
            else a++;
            if (a<0) return 0;
        }
        a=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='('&&arr[i]=='1') a--;
            else a++;
            if (a<0) return 0;
        }
        return 1;
    }
};