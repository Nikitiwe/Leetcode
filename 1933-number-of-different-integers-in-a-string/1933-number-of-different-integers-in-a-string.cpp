class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_set<string> m;
        s+=' ';
        string a="q";
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                if (a=="q") a=s[i];
                else
                {
                    a+=s[i];
                }
            }
            else
            {
                if (a!="q")
                {
                    reverse(a.begin(), a.end());
                    while (a.back()=='0'&&a.size()>1) a.pop_back();
                    m.insert(a);
                    a="q";
                }
            }
        }
        return m.size();
    }
};