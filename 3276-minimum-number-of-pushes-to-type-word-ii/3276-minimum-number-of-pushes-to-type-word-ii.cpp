class Solution {
public:
    int minimumPushes(string word) {
        if (word.size()<8) return word.size();
        vector<int> w(26, 0);
        for (int i=0; i!=word.size(); i++)
        {
            w[word[i]-'a']++;
        }
        sort(w.begin(), w.end());
        int ans=0, count=0;
        for (int i=25; i>=0; i--)
        {
            if (w[i]!=0) {count++; ans=ans+w[i]*((count+7)/8);}
        }
        return ans;
    }
};