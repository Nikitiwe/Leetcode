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
        int ans=0, count=0, q=1;
        for (int i=25; i>=0; i--)
        {
            if (w[i]!=0)
            {
                count++;
                if (count==9||count==17||count==25) q++;
                ans=ans+w[i]*q;
            }
            else break;
        }
        return ans;
    }
};