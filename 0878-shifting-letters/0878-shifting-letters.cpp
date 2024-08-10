class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i=s.size()-1; i>0; i--)
        {
            shifts[i]%=26;
            shifts[i-1]+=shifts[i];
        }
        shifts[0]%=26;
        for (int i=0; i!=s.size(); i++)
        {
            s[i]='a'+(s[i]-'a'+shifts[i])%26;
        }
        return s;
    }
};