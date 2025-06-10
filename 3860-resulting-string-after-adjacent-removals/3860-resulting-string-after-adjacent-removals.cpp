class Solution {
public:
    string resultingString(string s) {
        stack<char> q;
        for (int i=0; i<s.size(); i++)
        {
            if (q.size() > 0)
            {
                if ((q.top() + 1 - s[i] + 26) % 26 == 0 || (q.top() - 1 - s[i] + 26) % 26 == 0)
                {
                    q.pop();
                }
                else q.push(s[i]);
            }
            else q.push(s[i]);
        }
        string ans;
        while (q.size() > 0)
        {
            ans += q.top();
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};