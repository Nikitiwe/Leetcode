class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size()<k) return 0;
        vector<int> abc(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            abc[s[i]-'a']++;
        }
        int count=0;
        for (int i=0; i!=26; i++)
        {
            count=count+abc[i]%2;
        }
        if (count<=k) return 1;
        else return 0;
    }
};