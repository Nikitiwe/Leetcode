class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans;
        stack<char> q;
        for (int i=0; i!=s.size(); i++)
        {
            if (k == 0) q.push(s[i]);
            else
            {
                if (q.size() > 0)
                {
                    while (q.size() > 0 && q.top() > s[i] && k > 0)
                    {
                        q.pop();
                        k--;
                    }
                }
                q.push(s[i]);
            }
        }
        while (q.size() > 0)
        {
            ans += q.top();
            q.pop();
        }
        while (ans.size() > 0 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        while (ans.size() > 0 && k > 0)
        {
            ans.pop_back();
            k--;
        }
        if (ans.size() > 0)return ans;
        else return "0";
    }
};