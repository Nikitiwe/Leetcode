class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        unordered_map<int, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            m[s[i]-'a']++;
            if (m[s[i]-'a']>1)
            {
                ans++;
                m.clear();
            }
            m[s[i]-'a']++;
        }
        return ans;
    }
};