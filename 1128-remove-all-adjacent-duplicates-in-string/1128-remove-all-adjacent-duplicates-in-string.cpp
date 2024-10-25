class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> m;
        for (int i=0; i!=s.size(); i++)
        {
            if (m.size()==0) m.push(s[i]);
            else
            {
                if (m.top()==s[i])
                {
                    m.pop();
                }
                else m.push(s[i]);
            }
        }
        s="";
        while (m.size()>0)
        {
            s+=m.top();
            m.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};