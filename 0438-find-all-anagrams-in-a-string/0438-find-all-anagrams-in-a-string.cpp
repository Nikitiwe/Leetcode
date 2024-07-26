class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, arr(26, 0), brr(26, 0);
        if (p.size()>s.size()) return ans;
        for (int i=0; i!=p.size(); i++) arr[s[i]-'a']++;
        for (int i=0; i!=p.size(); i++) brr[p[i]-'a']++;
        if (arr==brr) ans.push_back(0);
        for (int i=p.size(); i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
            arr[s[i-p.size()]-'a']--;
            if (arr==brr) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};