class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans=0;
        int sym[26][2];
        for (int i=0; i!=s.size(); i++)
        {
            sym[s[i]-'a'][0]=i;
            sym[t[i]-'a'][1]=i;
        }
        for (int i=0; i!=26; i++) {ans=ans+abs(sym[i][0]-sym[i][1]);}
        return ans;
    }
};