class Solution {
public:
    vector<string> divideString(string s, int k, char f) {
        vector<string> ans;
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            t+=s[i];
            if (t.size()==k)
            {
                ans.push_back(t);
                t="";
            }
        }
        if (t.size()!=0)
        {
            while (t.size()<k) t+=f;
            ans.push_back(t);
        }
        return ans;
    }
};