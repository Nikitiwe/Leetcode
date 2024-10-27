class Solution {
public:
    string makeGood(string s) {
        stack<char> m;
        int a='a'-'A', b='A'-'a';
        for (int i=0; i!=s.size(); i++)
        {
            if (m.size()>0)
            {
                if (m.top()-s[i]==a||m.top()-s[i]==b)
                {
                    m.pop();
                }
                else m.push(s[i]);
            }
            else m.push(s[i]);
        }
        string ans;
        while (m.size()>0)
        {
            ans+=m.top();
            m.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};