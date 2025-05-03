class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& s) {
        vector<bool> isit(s.size(), 1);
        queue<string> q;
        queue<int> l;
        q.push(beginWord);
        l.push(1);
        while (q.size() > 0)
        {
            string t = q.front();
            int ans = l.front();
            q.pop();
            l.pop();
            for (int i=0; i!=s.size(); i++) if (isit[i] == 1)
            {
                int c = 0;
                for (int j=0; j!=s[i].size(); j++)
                {
                    if (t[j] != s[i][j]) c++;
                }
                if (c == 1)
                {
                    if (s[i] == endWord) return ans + 1;
                    isit[i] = 0;
                    q.push(s[i]);
                    l.push(ans + 1);
                }
            }
        }
        return 0;
    }
};