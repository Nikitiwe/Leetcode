class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int ans=1;
        for (int i=0; i!=s1.size(); i++)
        {
            if (s1[i]<s2[i]) {ans=0; break;}
        }
        if (ans==1) return 1;
        else
        {
            ans=1;
            for (int i=0; i!=s1.size(); i++)
            {
                if (s1[i]>s2[i]) {ans=0; break;}
            }
            return ans;
        }
    }
};