class Solution {
public:
    string simplifyPath(string s) {
        stack<string> q;
        s += '/';
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '/')
            {
                if (t == "..")
                {
                    if (q.size() > 0) q.pop();
                }
                else if (t.size() > 0 && t != ".")
                {
                    q.push(t);
                }
                t = "";
            }
            else t += s[i];
        }
        vector<string> arr;
        while (q.size() > 0)
        {
            arr.push_back(q.top());
            q.pop();
        }
        string ans;
        for (int i=arr.size()-1; i>=0; i--)
        {
            ans += '/';
            ans += arr[i];
        }
        if (ans.size() == 0) ans += '/';
        return ans;
    }
};