class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string s;
        for (int l=0; l<max(w1.size(), w2.size()); l++)
        {
            if (l<w1.size()) s+=w1[l];
            if (l<w2.size()) s+=w2[l];
        }
        return s;
    }
};