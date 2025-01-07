class Solution {
public:
    string decodeMessage(string k, string s) {
        unordered_map<char, char> m;
        int a=0;
        for (int i=0; i!=k.size(); i++)
        {
            if (k[i]!=' '&&m.count(k[i])==0)
            {
                m[k[i]]='a'+a;
                a++;
            }
        }
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ') s[i]=m[s[i]];
        }
        return s;
    }
};