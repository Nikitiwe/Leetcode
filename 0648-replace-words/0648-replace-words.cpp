class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string> m(d.begin(), d.end());
        s+=' ';
        string ans, t, temp="";
        for (int i=0; i!=s.size(); i++)
        {
            if (temp.size()==0&&s[i]!=' ')
            {
                t+=s[i];
                if (m.count(t)>0)
                {
                    temp=t;
                }
            }
            else if (s[i]==' ')
            {
                if (temp.size()==0) ans+=t;
                else ans+=temp;
                ans+=' ';
                t="";
                temp="";
            }
        }
        ans.pop_back();
        return ans;
    }
};