class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int, int>> q; // буква - ид
        //vector<int> c(26, 0);
        //int count = 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] != '*')
            {
                q.push({ - s[i], i});
                //count++;
                //c[s[i] - 'a']++;
            }
            else
            {
                //if (c[q.top().first - 'a'] > 1) q.pop();
                q.pop();
            }
        }
        vector<bool> isit(s.size(), 0);
        while (q.size() > 0)
        {
            isit[q.top().second] = 1;
            q.pop();
        }
        string ans;
        for (int i=0; i!=s.size(); i++)
        {
            if (isit[i] == 1) ans += s[i];
        }
        return ans;
    }
};