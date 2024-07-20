class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word2.size()!=word1.size()) return 0;
        vector<int> w1(26, 0), w2(26, 0);
        for (int i=0; i!=word1.size(); i++)
        {
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
        for (int i=0; i!=26; i++)
        {
            if (w1[i]==0&&w2[i]>0||w1[i]>0&&w2[i]==0) return 0;
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        if (w1==w2) return 1;
        else return 0;
    }
};