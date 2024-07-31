class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int idm;
        for (int i=0; i<s.size()-1; i++)
        {
            idm=i;
            for (int j=i+1; j<s.size(); j++) if (s[idm]<=s[j]) idm=j;
            if (s[idm]>s[i]) {swap (s[idm], s[i]); break;}
        }
        return stoi(s);
    }
};