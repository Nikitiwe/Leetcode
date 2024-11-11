class Solution {
public:
    string reformat(string s) {
        string n, l;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='0'&&s[i]<='9') n+=s[i];
            else l+=s[i];
        }
        string ans(s.size(), 'Z');
        //return to_string(n.size());
        if ((int)l.size()-(int)n.size()>1||(int)n.size()-(int)l.size()>1) return "";
        else if ((int)l.size()-(int)n.size()>=0)
        {
            for (int i=0; i<ans.size(); i+=2) ans[i]=l[i/2];
            for (int i=1; i<ans.size(); i+=2) ans[i]=n[i/2];
        }
        else
        {
            for (int i=0; i<ans.size(); i+=2) ans[i]=n[i/2];
            for (int i=1; i<ans.size(); i+=2) ans[i]=l[i/2];
        }
        return ans;
    }
};