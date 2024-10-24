class Solution {
public:
    int countWords(vector<string>& w1, vector<string>& w2) {
        unordered_map<string, int> m;
        int ans=0;
        for (int i=0; i!=w1.size(); i++)
        {
            m[w1[i]]++;
        }
        for (int i=0; i!=w2.size(); i++)
        {
            if (m[w2[i]]==1) m[w2[i]]--;
            else m[w2[i]]-=1001;
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==0) ans++;
        }
        return ans;
    }
};