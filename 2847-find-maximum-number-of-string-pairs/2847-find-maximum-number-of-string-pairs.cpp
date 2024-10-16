class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& w) {
        unordered_set<string> m;
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            if (m.count(w[i])>0)
            {
                ans++;
                m.erase(w[i]);
            }
            else
            {
                reverse(w[i].begin(), w[i].end());
                m.insert(w[i]);
            }
        }
        return ans;
    }
};