class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        long ans=999999;
        for (int i=0; i!=s.size(); i++)
        {
            if (m.count(s[i])==0) m.insert({s[i], 1});
            else m[s[i]]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            if (it->second==1) ans=min(ans, distance(s.begin(), find(s.begin(), s.end(), it->first)));
        }
        if (ans!=999999) return ans;
        else return -1;
    }
};