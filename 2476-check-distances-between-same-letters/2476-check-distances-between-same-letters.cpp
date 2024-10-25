class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        for (int i=0; i!=s.size(); i++)
        {
            if ((i+1+d[s[i]-'a']<s.size()&&s[i]==s[i+1+d[s[i]-'a']])||
                (i-1-d[s[i]-'a']>=0&&s[i]==s[i-1-d[s[i]-'a']])) continue;
            else return 0;
        }
        return 1;
    }
};