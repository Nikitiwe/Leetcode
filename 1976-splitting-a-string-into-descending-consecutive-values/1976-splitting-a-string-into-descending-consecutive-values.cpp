class Solution {
public:
    bool splitString(string s) {
        if (s.size()==1) return 0;
        string a;
        for (int i=0; i<s.size()-1; i++)
        {
            a+=s[i];
            long long prev=stoll(a);
            if (prev>=100000000000) return 0;
            string b;
            for (int j=i+1; j<s.size(); j++)
            {
                b+=s[j];
                if (stoll(b)<prev-1) continue;
                else if (stoll(b)==prev-1)
                {
                    if (j==s.size()-1) return 1;
                    if (stoll(b)!=0)
                    {
                        prev=stoll(b);
                        b="";
                    }
                }
                else break;
            }
        }
        return 0;
    }
};