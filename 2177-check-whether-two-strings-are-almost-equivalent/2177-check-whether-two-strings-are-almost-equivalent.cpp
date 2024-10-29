class Solution {
public:
    bool checkAlmostEquivalent(string s, string w) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        for (int i=0; i!=w.size(); i++) arr[w[i]-'a']--;
        for (int i=0; i!=26; i++) if (arr[i]>3||arr[i]<-3) return 0;
        return 1;
    }
};