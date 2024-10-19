class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        unordered_map<char, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]]>1)
            {
                ans++;
                m.clear();
            }
            m[s[i]]++;
        }
        return ans;
    }
};