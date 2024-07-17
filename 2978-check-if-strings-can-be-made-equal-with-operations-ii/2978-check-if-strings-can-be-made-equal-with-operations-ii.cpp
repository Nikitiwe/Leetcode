class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1e, s1o, s2e, s2o;
        for (int i=0; i!=s1.size(); i++)
        {
            if (i%2==0)
            {
                s1e+=s1[i];
                s2e+=s2[i];
            }
            else
            {
                s1o+=s1[i];
                s2o+=s2[i];
            }
        }
        sort(s1o.begin(), s1o.end());
        sort(s2o.begin(), s2o.end());
        sort(s1e.begin(), s1e.end());
        sort(s2e.begin(), s2e.end());
        if (s1o==s2o&&s1e==s2e) return 1;
        else return 0;
    }
};