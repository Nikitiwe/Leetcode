class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        for (int i=0; i!=s.size()/k; i++)
        {
            int t=0;
            for (int j=0; j!=k; j++)
            {
                t+=s[i*k+j]-'a';
            }
            t%=26;
            ans.push_back('a'+t);
        }
        return ans;
    }
};