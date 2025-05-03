class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '(') q.push(s[i]);
            else if (s[i] == '[') q.push(s[i]);
            else if (s[i] == '{') q.push(s[i]);
            else if (s[i] == ')')
            {
                if (q.size() > 0 && q.top() == '(') q.pop();
                else return 0;
            }
            else if (s[i] == ']')
            {
                if (q.size() > 0 && q.top() == '[') q.pop();
                else return 0;
            }
            else if (s[i] == '}')
            {
                if (q.size() > 0 && q.top() == '{') q.pop();
                else return 0;
            }
        }
        if (q.size() > 0) return 0;
        return 1;
    }
};