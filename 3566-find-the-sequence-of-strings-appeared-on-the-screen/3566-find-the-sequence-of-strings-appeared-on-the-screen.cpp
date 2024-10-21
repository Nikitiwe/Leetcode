class Solution {
public:
    vector<string> stringSequence(string t) {
        vector<string> ans;
        string s;
        for (int i=0; i!=t.size(); i++)
        {
            s+='a';
            ans.push_back(s);
            while(s[i]!=t[i])
            {
                s[i]++;
                ans.push_back(s);
            }
        }
        return ans;
    }
};