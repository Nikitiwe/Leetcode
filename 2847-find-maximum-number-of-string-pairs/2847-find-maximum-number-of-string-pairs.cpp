class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& w) {
        unordered_map<string, int> m;
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            if (m.count(w[i])>0)
            {
                ans++;
                m[w[i]]--;
                if (m[w[i]]==0) m.erase(w[i]);
            }
            else
            {
                reverse(w[i].begin(), w[i].end());
                m[w[i]]++;
            }
        }
        return ans;
    }
};