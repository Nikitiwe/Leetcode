class Solution {
public:
    string mostCommonWord(string s, vector<string>& b) {
        unordered_map<string, int> m;
        for (int i=0; i!=b.size(); i++) m[b[i]]=-2000;
        s+=' ';
        string ans(2000, 'z'), t;
        //m[ans]=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a'&&s[i]<='z') t+=s[i];
            else if (s[i]>='A'&&s[i]<='Z') t+=s[i]-'A'+'a';
            else
            {
                m[t]++;
                if (t!=""&&m[t]>m[ans]) ans=t;
                t="";
            }
        }
        return ans;        
    }
};